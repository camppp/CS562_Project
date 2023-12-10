public int findMaxColorComponent(byte[][] m_ubComponents) {
    int max = 0;
    for (int i = 0; i < m_ubComponents.length; i++) {
        for (int j = 0; j < m_ubComponents[i].length; j++) {
            if (m_ubComponents[i][j] > max) {
                max = m_ubComponents[i][j];
            }
        }
    }
    return max;
}
