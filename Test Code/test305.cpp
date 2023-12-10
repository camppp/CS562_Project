void revMatrix44::transpose() {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            // Swap m[i][j] and m[j][i]
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

revMatrix44::~revMatrix44() {
    // Destructor implementation if needed
}
