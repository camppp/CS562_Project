int averageDistance() {
    if (pointsArray.size() == 0) {
        return 0; // Return 0 if the collection is empty
    }

    double totalDistance = 0;
    int numPairs = 0;

    for (size_t i = 0; i < pointsArray.size(); ++i) {
        for (size_t j = i + 1; j < pointsArray.size(); ++j) {
            // Calculate the distance between points i and j
            int dx = pointsArray[j].x - pointsArray[i].x;
            int dy = pointsArray[j].y - pointsArray[i].y;
            double distance = sqrt(dx * dx + dy * dy);
            totalDistance += distance;
            numPairs++;
        }
    }

    // Calculate the average distance and round it to the nearest integer
    int avgDistance = static_cast<int>(round(totalDistance / numPairs));
    return avgDistance;
}
