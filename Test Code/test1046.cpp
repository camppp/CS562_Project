java
public int findMaxColorComponent(byte[][] m_ubComponents) {
    int maxComponent = m_ubComponents[0][0];  // Initialize maxComponent with the first element

    for (int i = 0; i < m_ubComponents.length; i++) {
        for (int j = 0; j < m_ubComponents[0].length; j++) {
            if (m_ubComponents[i][j] > maxComponent) {
                maxComponent = m_ubComponents[i][j];  // Update maxComponent if a larger value is found
            }
        }
    }

    return maxComponent;
}
