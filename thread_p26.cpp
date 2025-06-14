#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

struct CWFuture {
    int join() { return 1; } // Simulate work, returns word count
    bool isDone() { return true; }
};

CWFuture countWords(int machineId, int docId) {
    // Simulated API: would run countWords on real machine
    return CWFuture();
}

class WordCounter {
private:
    int numDocs;
    int maxMachines;
    std::queue<int> taskQueue;
    std::mutex queueMutex;
    std::condition_variable cvTask;

    std::atomic<int> totalCount{0};
    std::atomic<int> processedTasks{0};

public:
    WordCounter(int numDocs, int maxMachines)
        : numDocs(numDocs), maxMachines(maxMachines) {}

    void worker(int machineId) {
        while (true) {
            int docId = -1;
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                cvTask.wait(lock, [&]() { return !taskQueue.empty() || processedTasks == numDocs; });

                if (taskQueue.empty()) {
                    if (processedTasks == numDocs) return; // All done
                    continue; // Spurious wakeup
                }

                // Assign next task to this machine
                docId = taskQueue.front();
                taskQueue.pop();
            }

            // Simulate processing on machineId
            CWFuture future = countWords(machineId, docId);
            int count = future.join();
            totalCount += count;

            processedTasks++; // Atomically mark this doc done

            // Notify other waiting threads in case taskQueue got empty and done
            cvTask.notify_all();
        }
    }

    int getTotalCount() {
        std::vector<std::thread> threads;

        // Launch machine (worker) threads
        for (int i = 0; i < maxMachines; ++i) {
            threads.emplace_back(&WordCounter::worker, this, i);
        }

        // Producer thread adds tasks
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            for (int docId = 0; docId < numDocs; ++docId) {
                taskQueue.push(docId);
            }
        }
        cvTask.notify_all(); // Wake up all machines to pick their first task

        // Wait for all threads to finish
        for (auto& t : threads) {
            t.join();
        }

        return totalCount;
    }
};

int main() {
    int numDocs = 100;
    int maxMachines = 4;

    WordCounter wc(numDocs, maxMachines);
    int total = wc.getTotalCount();
    std::cout << "Total word count: " << total << std::endl;

    return 0;
}
