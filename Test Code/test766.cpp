void setPixelColor(int index, int red, int green, int blue) {
  // Assuming the RGB LED strip is connected to digital pins 6, 5, and 3 for red, green, and blue respectively
  // This example uses the FastLED library for controlling the RGB LED strip
  // You may need to include the FastLED library and define the LED strip configuration based on your hardware setup

  // Assuming you have defined the LED strip as follows:
  // #define NUM_LEDS 60
  // CRGB leds[NUM_LEDS];

  // Set the color of the specified LED
  leds[index] = CRGB(red, green, blue);

  // Update the LED strip to reflect the changes
  FastLED.show();
}
