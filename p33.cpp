// https://leetcode.com/discuss/post/6617221/google-l3-interview-experience-by-anonym-nt48/

// Create a double ended queue functionalty such as push / pop - front / back, size of double ended queue and printing all elements of queue using only map data structure.

#include <iostream>
#include <unordered_map>
using namespace std;

template<typename T>
class DequeWithMap {
private:
    unordered_map<int, T> data;
    int front_idx, back_idx;

public:
    DequeWithMap() : front_idx(0), back_idx(0) {}

    void push_front(const T& value) {
        front_idx--;
        data[front_idx] = value;
    }

    void push_back(const T& value) {
        data[back_idx] = value;
        back_idx++;
    }

    void pop_front() {
        if (size() == 0) {
            cout << "Deque is empty!\n";
            return;
        }
        data.erase(front_idx);
        front_idx++;
    }

    void pop_back() {
        if (size() == 0) {
            cout << "Deque is empty!\n";
            return;
        }
        back_idx--;
        data.erase(back_idx);
    }

    int size() const {
        return back_idx - front_idx;
    }

    void print() const {
        if (size() == 0) {
            cout << "Deque is empty!\n";
            return;
        }
        for (int i = front_idx; i < back_idx; i++) {
            cout << data.at(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    DequeWithMap<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.print(); // Expected: 20 10 30

    dq.pop_front();
    dq.print(); // Expected: 10 30

    dq.pop_back();
    dq.print(); // Expected: 10

    cout << "Size: " << dq.size() << endl; // Expected: 1

    dq.pop_back();
    dq.print(); // Expected: Deque is empty!

    return 0;
}
