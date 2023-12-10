StatusCode checkVBlankStatus() {
    if (POSTAndHardwareTests::VBlankOK()) {
        return sOK;
    } else {
        return sKO;
    }
}
