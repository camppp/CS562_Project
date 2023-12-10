void projectAllVertices(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        // Calculate the projected 2D position of the current vertex
        const auto& vertex = mVertices[i];
        const auto& position = vertex.first;
        const auto& projectedPosition = vertex.second;

        // Calculate the projected z-coordinate of the current vertex
        const auto projectedZ = position.z * projectedPosition.x + position.y * projectedPosition.y + position.z * projectedPosition.z;

        // Update the projected 2D position of the current vertex
        projectedPosition.x = position.x;
        projectedPosition.y = position.y;
        projectedPosition.z = projectedZ;
    }
}
