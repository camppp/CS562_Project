void resetRFM() {
    // Reset the RFM module to its default state
    // ...
}

void initRFM() {
    // Initialize the RFM module
    // ...

    // Set the rfm_init_success flag to true if initialization was successful
    if (rfm_init_success) {
        rfm_init_success = true;
    } else {
        rfm_init_success = false;
    }
}

void showStatus() {
    // Check the rfm_init_success flag and set the LED strip color accordingly
    if (rfm_init_success) {
        strip.setPixelColor(0, 0, 255, 0); // Green
    } else {
        strip.setPixelColor(0, 255, 0, 0); // Red
    }
}
