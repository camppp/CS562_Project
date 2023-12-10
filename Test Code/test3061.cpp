void processParallelConfig(const Args& args, int& num_threads, int& use_numa) {
  #if defined(KOKKOS_ENABLE_OPENMP) || defined(KOKKOS_ENABLE_THREADS) || \
      defined(KOKKOS_ENABLE_OPENMPTARGET) || defined(KOKKOS_ENABLE_HPX)
    num_threads = args.num_threads;
  #endif
  #if defined(KOKKOS_ENABLE_THREADS) || defined(KOKKOS_ENABLE_OPENMPTARGET)
    use_numa = args.num_numa;
  #endif
}
