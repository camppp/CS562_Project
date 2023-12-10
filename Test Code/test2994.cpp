class LAPACK {
public:
  int EstimateWorkSizeForQR(int num_rows, int num_cols) {
    #ifdef CERES_NO_LAPACK
      LOG(FATAL) << "Ceres was built without a LAPACK library.";
      return -1;
    #else
      // Estimate the work size required for QR decomposition
      // using the LAPACK routine DGEQRF.
      // The work size is the maximum of the lwork parameter
      // required by DGEQRF and the size of the array tau.
      int lwork = -1;
      int liwork = -1;
      int info = 0;
      double* tau = new double[num_cols];
      double* work = new double[num_cols];
      DGEQRF(num_rows, num_cols, work, num_cols, tau, lwork, liwork, info);
      if (info != 0) {
        LOG(FATAL) << "Error in DGEQRF: " << info;
        return -1;
      }
      int work_size = std::max(lwork, num_cols);
      delete[] tau;
      delete[] work;
      return work_size;
    #endif
  }
};
