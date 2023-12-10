int averageDistance() {
    int sum = 0;
    for (int i = 0; i < pointsArray.size(); i++) {
        for (int j = i + 1; j < pointsArray.size(); j++) {
            sum += distance(pointsArray[i], pointsArray[j]);
        }
    }
    return sum / (pointsArray.size() * (pointsArray.size() - 1)) + 0.5;
}
