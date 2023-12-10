// Define the GetMapPosition function to project the vertex onto the map
MapPosition GetMapPosition(Vertex point) {
    // Implement the projection logic here based on the map's coordinate system
    // Example: 
    // MapPosition projectedPosition = PerformProjection(point);
    // return projectedPosition;
}

// Call the GetMapPosition function for each vertex and append the projected positions to MapProjectionPolygon
assert(MapProjectionPolygon.Vertices().IsEmpty());

for (auto point : Polygon.Vertices()) {
    auto position = GetMapPosition(point);
    MapProjectionPolygon.AppendVertex(position);
}
