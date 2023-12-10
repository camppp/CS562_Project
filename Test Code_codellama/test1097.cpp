#include <iostream>

class Rectangle {
private:
    int length;
    int width;

public:
    void setLength(int len) {
        length = len;
    }

    void setWidth(int wid) {
        width = wid;
    }

    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }
};

int main() {
    Rectangle rect;
    rect.setLength(5);
    rect.setWidth(3);
    std::cout << "Length: " << rect.getLength() << ", Width: " << rect.getWidth() << std::endl;
    return 0;
}
