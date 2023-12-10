class ImagePieceManager {
private:
    double mImageHeight;
    double mImagePieceWidth;
    double mImagePieceHeight;
    double mPieceXPosition;
    double mPieceYPosition;

public:
    ImagePieceManager() {}

    void setImageHeight(double height) {
        mImageHeight = height;
    }

    void setImagePieceDimensions(double width, double height) {
        mImagePieceWidth = width;
        mImagePieceHeight = height;
    }

    void setImagePiecePosition(double x, double y) {
        mPieceXPosition = x;
        mPieceYPosition = y;

        // Ensure that the position of the image piece is within the bounds of the overall image
        if (mPieceXPosition < 0 || mPieceXPosition > mImageHeight - mImagePieceWidth) {
            mPieceXPosition = 0;
        }

        if (mPieceYPosition < 0 || mPieceYPosition > mImageHeight - mImagePieceHeight) {
            mPieceYPosition = 0;
        }
    }
};
