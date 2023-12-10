void populateAnimationParameters(const XML& xmlData, Quad* quads, int numQuads) {
    for (int i = 0; i < numQuads; i++) {
        quads[i].animaScaley = xmlData.getValue("QUADS:QUAD_" + ofToString(i) + ":ANIMA:SCALE_Y", 1.0);
        quads[i].animaScalez = xmlData.getValue("QUADS:QUAD_" + ofToString(i) + ":ANIMA:SCALE_Z", 1.0);
        quads[i].animaRotateX = xmlData.getValue("QUADS:QUAD_" + ofToString(i) + ":ANIMA:ROTATE_X", 0.0);
        quads[i].animaRotateY = xmlData.getValue("QUADS:QUAD_" + ofToString(i) + ":ANIMA:ROTATE_Y", 0.0);
    }
}
