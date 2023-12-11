import cv2
import numpy as np

def detect_corners(image):
    # Convert the image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply the Harris corner detection algorithm
    gray = np.float32(gray)
    dst = cv2.cornerHarris(gray, 2, 3, 0.04)

    # Apply a threshold to the corner detection
    dst = cv2.dilate(dst, None)
    image[dst > 0.01 * dst.max()] = [0, 0, 255]

    # Find the coordinates of the corners
    corners = np.argwhere(dst > 0.01 * dst.max())

    return corners