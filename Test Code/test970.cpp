bool addNewPoint(Point p2, double width, double dx2, double dy2, Collection* points) {
    Point p;
    p.x = p2.x + width * dy2;
    p.y = p2.y - width * dx2;
    p.z = p2.z;

    if (!points->Add(&p)) {
        return false;
    }
    return true;
}
