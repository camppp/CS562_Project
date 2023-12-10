c
void processRotaryEncoder(byte* rotADef, byte* listenerFP, byte otherBitIdx) {
    // Calculate the difference in the state of the two pins
    signed char delta = (rotADef[otherBitIdx] & B00011111) - (rotBDef[otherBitIdx] & B00011111);

    // Update the state of rotADef and rotBDef
    if (delta != 0) {
        rotADef[otherBitIdx] = (rotADef[otherBitIdx] & B00011111) | (delta & B00011111);
        rotBDef[otherBitIdx] = (rotBDef[otherBitIdx] & B00011111) | (delta & B00011111);
    }

    // Print debug information
    printf("Rotary encoder state: %d, %d\n", rotADef[otherBitIdx], rotBDef[otherBitIdx]);
}
