void calculatePermeability(double Q[3][3], double F[3][3], double m_perm0, double m_perm1[3], double m_perm2[3], double J, double phi0, double m_alpha0, double m_alpha[3], double m_M0, double m_M[3], double k[3]) {
    // Calculate the strain tensor
    double eps[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            eps[i][j] = 0.5 * (F[i][j] - 1.0);
        }
    }

    // Calculate the strain-dependent permeability parameters
    double m_perm[3];
    for (int i = 0; i < 3; i++) {
        m_perm[i] = m_perm0 + m_perm1[i] * eps[i][0] + m_perm2[i] * eps[i][1];
    }

    // Calculate the strain-dependent permeability
    for (int i = 0; i < 3; i++) {
        k[i] = m_perm[i] * pow(J, m_alpha[i]) * pow(phi0, m_M[i]);
    }
}
