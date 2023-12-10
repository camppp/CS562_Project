void CalculateIndices(int WP, int LP, int HP, int WidthSegments, int LengthSegments, int HeightSegments) {
    int VertexIndex1, VertexIndex2, IndexIndex1, IndexIndex2;

    // Calculate the indices of vertices for the left and right faces of the box
    VertexIndex1 = 2 * (WP * LP + HP * LP);
    VertexIndex2 = VertexIndex1 + HP * WP;

    // Calculate the indices of faces for the left and right faces of the box
    IndexIndex1 = 12 * (LengthSegments * WidthSegments + LengthSegments * HeightSegments);
    IndexIndex2 = IndexIndex1 + (6 * WidthSegments * HeightSegments);

    // Iterate over the height and width segments to calculate the indices for each segment
    for (int j = 0; j < HeightSegments; ++j) {
        for (int i = 0; i < WidthSegments; ++i) {
            // Calculate indices for the right face of the box
            // Your implementation here
        }
    }
}
