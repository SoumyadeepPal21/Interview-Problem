
// https://leetcode.com/discuss/post/6787700/google-phone-screen-interview-experience-zdfp/


// if the jobs that comes at first should be done first

set<pair<int, int>> machineTimes;
for (int i = 0; i < k; i++) {
    machineTimes.insert({0, i});
}

for (int i = 0; i < n; i++) {
    int nextTaskStartTime = max(machineTimes.begin()->first, task[i].first);
    int nextTaskMachine = machineTimes.begin()->second;
    machinsTimes.erase(machineTimes.begin());
    machineTimes.insert({nextTaskStartTime + task[i].second - task[i].first, nextTaskMachine});
    machineId[i] = nextTaskMachine;
}



time when machine available 5, and jobs = [ {1, 5}, {3, 4}, {3, 5}, {4, 5}] =>


// take the machine which will be available first, say at time T.
// if there are some jobs available at time <= T, then we will take those jobs.
// if no jobs remaining wihin time T, then we will take the next job.


// if there are multiple available machine, which machine to take?
// the one which was available at first, if there are multiple then take minimum id
// or take the minimum id overall among all the machines available

for (int i = 0; i < k; i++) {
    machineTime.insert({0, i});
}

while (jobPtr < n) {
    // machine with id = machineID will finish it's job at time = time
    int time = machineTime.begin()->first;
    int machineId = machineTime.begin()->second;
    while (!machineTime.empty() && machineTime.begin()->first == time) {
        availmachines.insert(machineTime.begin()->second);
        machineTime.erase(machineTime.begin());
    }

    // queue all the jobs that has starting time <= time
    while (jobPtr < n && time >= jobs[jobPtr].first) {
        nextJobs.insert({jobs[jobPtr].second - jobs[jobPtr].first, jobsPtr});
        jobPtr++;
    }


    // say the machine that will end it's task at time = t, and the next job will start
    // at time t' > t
    int mxEndtime = machineTime.rbegin()->first;
    if (mxEndtime < jobs[jobPtr].first) {
        time = jobs[jobPtr].first;
        while (jobPtr < n && time >= jobs[jobPtr].first) {
            nextJobs.insert({jobs[jobPtr].second - jobs[jobPtr].first, jobsPtr});
            jobPtr++;
        }
    }

    if (availmachines.empty()) continue;

    int nextMachineId = *availmachines.begin();
    availmachines.erase(nextMachineId);
    int jobId = nextJobs.begin()->second;
    int jobTime = nextJobs.begin()->first;
    jobQueue.push_back(jobId);
    machineTime.insert({time + jobTime, machineId});
}

// https://leetcode.com/discuss/post/4701657/google-onsite-l3-by-anonymous_user-71hb/


// https://leetcode.com/problems/single-threaded-cpu/
task[0] = id
          task[1] = startetime
                    task[2] = exec time

                              int time = 0;
int taskPtr = 0;
set<pair<int, int>> availTaks;

while (taskPtr < n) {
    // no task in the queue, should take the next task
    if (availTasks.empty()) {
        time = tasks[taskPtr][1];
        availTasks.insert({task[taskPtr][2], task[taskPtr][0]});
        taskPtr++;
    }

    // say cur time is T, so we should take all the tasks that have start tiem <= T
    while (taskPtr < n && time >= task[taskPtr][1]) {
        availTasks.insert({task[taskPtr][2], task[taskPtr][0]});
        taskPtr++;
    }

    pair<int, int> job = availTasks.begin();
    int jobId = job.second;
    time += job.first;
    ans.push_back(jobId);
}


// k cpu's


while (!runningMachines.empty() && taskPtr < n) {
    if (runningMachines.empty() && taskPtr < n) {
        time = tasks[taskPtr][1];
    } else {
        time = *runningMachines.begin();
    }
    while (taskPtr < n && time >= task[taskPtr][1]) {
        availTasks.insert({task[taskPtr][2], task[taskPtr][0]});
        taskPtr++;
    }



}


