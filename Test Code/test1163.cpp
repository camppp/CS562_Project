#include <iostream>

class ImagePieceManager {
private:
    double mImageHeight{0};
    double mImagePieceWidth{0};
    double mImagePieceHeight{0};
    double mPieceXPosition{0};
    double mPieceYPosition{0};

public:
    void setImageHeight(double height) {
        mImageHeight = height;
    }

    void setImagePieceDimensions(double width, double height) {
        mImagePieceWidth = width;
        mImagePieceHeight = height;
    }

    void setImagePiecePosition(double x, double y) {
        if (x >= 0 && x + mImagePieceWidth <= mImageHeight) {
            mPieceXPosition = x;
        } else {
            std::cout << "Invalid x-coordinate position for the image piece." << std::endl;
        }

        if (y >= 0 && y + mImagePieceHeight <= mImageHeight) {
            mPieceYPosition = y;
        } else {
            std::cout << "Invalid y-coordinate position for the image piece." << std::endl;
        }
    }
};

int main() {
    ImagePieceManager manager;
    manager.setImageHeight(100);
    manager.setImagePieceDimensions(20, 30);
    manager.setImagePiecePosition(10, 20);  // Valid position
    manager.setImagePiecePosition(90, 20);  // Invalid x-coordinate position
    manager.setImagePiecePosition(10, 80);  // Invalid y-coordinate position
    return 0;
}
