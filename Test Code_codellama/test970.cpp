bool addNewPoint(Point p2, double width, double dx2, double dy2, Collection* points) {
    // Calculate the new point's coordinates
    double x = p2.x + dx2 * width;
    double y = p2.y + dy2 * width;
    double z = p2.z;

    // Create a new point with the calculated coordinates
    Point newPoint(x, y, z);

    // Add the new point to the collection
    points->add(newPoint);

    // Return true if the new point was added successfully
    return true;
}
