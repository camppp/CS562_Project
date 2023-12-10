Scheduler* createScheduler(int num_procs, int num_levels, const vector<int>& fan_outs, const vector<int>& sizes, const vector<int>& block_sizes, char arg) {
    if (arg == '2') {
        return new HR2Scheduler(num_procs, num_levels, fan_outs, sizes, block_sizes, 0);
    } else if (arg == '3') {
        // More code for creating a scheduler based on input argument '3'
    } else {
        // Handle invalid input argument
        return nullptr;
    }
}
