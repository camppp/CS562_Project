#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

CircleShape create() {
    CircleShape circle;
    int radius = rand() % 50 + 20;  // Random radius between 20 and 70
    circle.setRadius(radius);
    int posX = rand() % 900 + 50;  // Random x position within the window
    int posY = rand() % 400 + 50;  // Random y position within the window
    circle.setPosition(posX, posY);
    int red = rand() % 256;  // Random red component for color
    int green = rand() % 256;  // Random green component for color
    int blue = rand() % 256;  // Random blue component for color
    circle.setFillColor(Color(red, green, blue));
    return circle;
}

int countIntersectingCircles(CircleShape arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            float dx = arr[i].getPosition().x - arr[j].getPosition().x;
            float dy = arr[i].getPosition().y - arr[j].getPosition().y;
            float distance = sqrt(dx * dx + dy * dy);
            if (distance < arr[i].getRadius() + arr[j].getRadius()) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    RenderWindow window(VideoMode(1000, 500), "Circles");
    srand(time(0));
    const int SIZE = 10;
    CircleShape* arr = new CircleShape[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = create();
    }
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < SIZE; i++) {
            window.draw(arr[i]);
        }
        int intersectingCount = countIntersectingCircles(arr, SIZE);
        std::cout << "Number of intersecting circles: " << intersectingCount << std::endl;
        window.display();
    }
    delete[] arr;
    return 0;
}
