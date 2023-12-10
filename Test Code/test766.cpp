void setPixelColor(int index, int red, int green, int blue) {
  // Calculate the PWM values for each color
  int redPWM = red * 255 / 255;
  int greenPWM = green * 255 / 255;
  int bluePWM = blue * 255 / 255;

  // Set the PWM values for each color
  analogWrite(redPin, redPWM);
  analogWrite(greenPin, greenPWM);
  analogWrite(bluePin, bluePWM);
}
