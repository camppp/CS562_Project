void processRotaryEncoder(byte* rotADef, byte* listenerFP, byte otherBitIdx) {
    byte otherBitIdx = rotADef[0] & 0x7;
    byte *rotBDef = (byte*)&(listenerFP[otherBitIdx]);

    signed char delta = (rotBDef[0] >> 5) - (rotADef[0] >> 5);
    if (delta != 0) {
        rotADef[0] &= B00011111;
        rotBDef[0] &= B00011111;
        DEBUG_PRINT(F("Process RotaryEncoder: fpA: "));
        DEBUG_PRINT((unsigned int)listenerFP[bitIdx], HEX);
        DEBUG_PRINT(F(", fpB: "));
        DEBUG_PRINT((unsigned int)listenerFP[otherBitIdx], HEX);
        DEBUG_PRINT(F(", BbitIdx: "));
    }
}
