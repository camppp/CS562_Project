void processParallelConfig(const Args& args, int& num_threads, int& use_numa) {
#ifdef USE_OPENMP
  num_threads = args.num_threads;
#endif

#ifdef USE_NUMA
  use_numa = args.num_numa;
#endif
}
