void CalculateIndices(int WP, int LP, int HP, int WidthSegments, int LengthSegments, int HeightSegments) {
    // Calculate the number of vertices and faces for each segment
    int numVertices = (WP + 1) * (LP + 1) * (HP + 1);
    int numFaces = (2 * WP + 1) * (2 * LP + 1) * (2 * HP + 1);

    // Calculate the indices of vertices and faces for each segment
    for (int w = 0; w < WP; w++) {
        for (int l = 0; l < LP; l++) {
            for (int h = 0; h < HP; h++) {
                // Calculate the indices of vertices for the current segment
                int v0 = w * (LP + 1) * (HP + 1) + l * (HP + 1) + h;
                int v1 = v0 + 1;
                int v2 = v0 + (LP + 1) * (HP + 1);
                int v3 = v2 + 1;

                // Calculate the indices of faces for the current segment
                int f0 = w * (2 * LP + 1) * (2 * HP + 1) + l * (2 * HP + 1) + h;
                int f1 = f0 + 1;
                int f2 = f0 + (2 * LP + 1) * (2 * HP + 1);
                int f3 = f2 + 1;

                // Add the indices of vertices and faces to the arrays
                vertices.push_back(v0);
                vertices.push_back(v1);
                vertices.push_back(v2);
                vertices.push_back(v3);

                faces.push_back(f0);
                faces.push_back(f1);
                faces.push_back(f2);
                faces.push_back(f3);
            }
        }
    }
}
