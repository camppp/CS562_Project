import cv2
import numpy as np

def detect_corners(image):
   # Convert the image to grayscale
   gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

   # Compute the gradient in the x and y directions
   sobel_x = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=3)
   sobel_y = cv2.Sobel(gray, cv2.CV_64F, 0, 1, ksize=3)

   # Compute the gradient magnitude and direction
   gradient_mag = np.sqrt(sobel_x**2 + sobel_y**2)
   gradient_dir = np.arctan2(sobel_y, sobel_x)

   # Compute the Harris response
   harris_response = np.zeros(gradient_mag.shape)
   for i in range(gradient_mag.shape[0]):
       for j in range(gradient_mag.shape[1]):
           harris_response[i, j] = np.abs(gradient_mag[i, j]) * np.cos(gradient_dir[i, j])

   # Threshold the Harris response to find corners
   corners = np.where(harris_response > 0.01 * np.max(harris_response))

   # Return the coordinates of the corners
   return corners