// 2. macros //
///////////////

#define EXPORT extern "C" __declspec(dllexport)

/////////////
// 3. main //
/////////////

EXPORT void setup_omp(){ // required when using vs
    SetEnvironmentVariable("OMP_WAIT_POLICY", "passive"); 
}

EXPORT void fun(double *X, double *Y, double *Z, int NX, int NY, int threads){
    // Set the number of threads for parallelization
    omp_set_num_threads(threads);

    // Perform the mathematical operation in parallel
    #pragma omp parallel for
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            Z[i*NY + j] = X[i] * Y[j];
        }
    }
}
