
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



while (jobPtr < n) {
    int time = machineTime.begin()->first;
    int machineId = machineTime.begin()->second;
    while (jobPtr < n && time >= jobs[jobPtr].first) {
        nextJobs.insert({jobs[jobPtr].second - jobs[jobPtr].first, jobsPtr});
        jobPtr++;
    }
    if (nextJobs.empty()) {
        nextJobs.insert({jobs[jobPtr].second - jobs[jobPtr].first, jobsPtr});
        time = jobs[jobPtr].first;
        jobPtr++;
    }
    // if the first machine availble should be given the next task, then
    // assingn the job to machine with id = machineId
    // otherwise
    while (machineTime.begin()->first <= time) {
        machines.insert(machineTime.begin()->second);
        machineTime.erase(machineTime.begin());
    }
    machineId = *machines.begin();
    machines.erase(machineId);


    int jobId = nextJobs.begin()->second;
    jobQueue.push_back(jobId);
    machineTime.insert({T[machineId], machineId});
    machineTime.insert({time + duration, machineId});
    T[machineId] = time + duration;
}



