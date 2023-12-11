bool toWkb(WKB& wkb, int type, const std::vector<Point>& coords) {
    // Initialize the WKB object with the appropriate header byte
    wkb.header = type;

    // Convert the coordinates to WKB format
    switch (type) {
        case POINT:
            wkb.coords = coords[0];
            break;
        case LINE:
            wkb.coords = coords[0];
            wkb.coords.push_back(coords[1]);
            break;
        case POLYGON:
            wkb.coords = coords[0];
            for (int i = 1; i < coords.size(); i++) {
                wkb.coords.push_back(coords[i]);
            }
            break;
        default:
            return false;
    }

    // Return true if the conversion was successful
    return true;
}
