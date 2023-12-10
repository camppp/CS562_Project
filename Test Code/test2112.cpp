#include <vector>
#include <fftw3.h>

std::vector<std::vector<double>> calculateDCT(const std::vector<std::vector<double>>& inputImage, int width, int height) {
    // Initialize FFTW plans and arrays
    fftw_plan plan;
    int n = width * height;
    double* in = (double*) fftw_malloc(sizeof(double) * n);
    double* out = (double*) fftw_malloc(sizeof(double) * n);
    fftw_complex* inDCT = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    fftw_complex* outDCT = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);

    // Create plan for forward DCT
    plan = fftw_plan_r2r_2d(width, height, in, out, FFTW_REDFT10, FFTW_REDFT10, FFTW_ESTIMATE);

    // Populate input array with image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            in[i * width + j] = inputImage[i][j];
        }
    }

    // Execute the plan to compute the DCT
    fftw_execute(plan);

    // Copy the computed DCT coefficients to the output array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            inDCT[i * width + j][0] = out[i * width + j];
            inDCT[i * width + j][1] = 0.0;  // Imaginary part is zero for real input
        }
    }

    // Clean up and free memory
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);

    // Convert the DCT coefficients to a 2D vector for output
    std::vector<std::vector<double>> dctCoefficients(height, std::vector<double>(width, 0.0));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            dctCoefficients[i][j] = inDCT[i * width + j][0];
        }
    }

    // Free memory for DCT coefficients
    fftw_free(inDCT);
    fftw_free(outDCT);

    return dctCoefficients;
}
