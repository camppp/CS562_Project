#include <cmath>

void calculatePermeability(double Q[3][3], double F[3][3], double m_perm0, double m_perm1[3], double m_perm2[3], double J, double phi0, double m_alpha0, double m_alpha[3], double m_M0, double m_M[3], double k[3]) {
    double m[3][3]; // Texture tensor in the current configuration
    for (int a = 0; a < 3; a++) {
        // Copy the texture direction in the reference configuration to V
        double V[3] = {Q[0][a], Q[1][a], Q[2][a]};
        // Evaluate texture tensor in the current configuration
        for (int i = 0; i < 3; i++) {
            m[a][i] = 0;
            for (int j = 0; j < 3; j++) {
                m[a][i] += F[i][j] * V[j];
            }
        }
    }

    // Calculate strain-dependent permeability
    double f, k0, k1[3], k2[3];
    k0 = m_perm0 * pow((J - phi0) / (1 - phi0), m_alpha0) * exp(m_M0 * (J * J - 1.0) / 2.0);
    for (int a = 0; a < 3; a++) {
        f = pow((J - phi0) / (1 - phi0), m_alpha[a]) * exp(m_M[a] * (J * J - 1.0) / 2.0);
        k1[a] = m_perm1[a] / (J * J) * f;
        k2[a] = 0.5 * m_perm2[a] / pow(J, 4) * f;
        k[a] = k0 + k1[a] + k2[a];
    }
}
