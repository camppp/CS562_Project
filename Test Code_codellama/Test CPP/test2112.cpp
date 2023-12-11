#include <fftw3.h>

std::vector<std::vector<double>> calculateDCT(const std::vector<std::vector<double>>& inputImage, int width, int height) {
    // Create FFTW plan for forward DCT computation
    fftw_plan plan = fftw_plan_dct(width, height, FFTW_FORWARD, FFTW_ESTIMATE);

    // Allocate memory for DCT coefficients
    std::vector<std::vector<double>> dctCoefficients(width, std::vector<double>(height));

    // Compute DCT using FFTW library
    fftw_execute_dct(plan, inputImage.data(), dctCoefficients.data());

    // Destroy FFTW plan
    fftw_destroy_plan(plan);

    return dctCoefficients;
}
