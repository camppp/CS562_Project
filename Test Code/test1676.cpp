StatusCode checkVBlankStatus() {
    if (VBlankOK()) {
        return sOK;
    } else {
        return sKO;
    }
}
