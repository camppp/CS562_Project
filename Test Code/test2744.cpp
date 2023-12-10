Scheduler* createScheduler(int num_procs, int num_levels, const vector<int>& fan_outs, const vector<int>& sizes, const vector<int>& block_sizes, char arg) {
    Scheduler* sched = nullptr;
    if (arg == '2') {
        sched = new HR2Scheduler(num_procs, num_levels, fan_outs, sizes, block_sizes, 0);
    } else if (arg == '3') {
        // Add logic to create a scheduler based on input argument '3'
        sched = new CustomScheduler(num_procs, num_levels, fan_outs, sizes, block_sizes, 1);
    }
    return sched;
}
