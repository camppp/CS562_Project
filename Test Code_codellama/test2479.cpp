void GetMapPosition(const Polygon& polygon, const MapProjectionPolygon& mapProjectionPolygon) {
    // Iterate over the vertices of the original polygon
    for (const auto& vertex : polygon.Vertices()) {
        // Get the projected position of the vertex on the map
        const auto& projectedPosition = GetProjectedPosition(vertex);

        // Append the projected position to the map projection polygon
        mapProjectionPolygon.AppendVertex(projectedPosition);
    }
}
