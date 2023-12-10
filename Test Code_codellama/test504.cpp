void populateAnimationParameters(const XML& xmlData, Quad* quads, int numQuads) {
    // Iterate over each quad in the XML data
    for (int i = 0; i < numQuads; i++) {
        // Get the current quad's animation parameters
        const XML::Element& quadElement = xmlData.getChild("quads").getChild(i);
        float animaScaley = quadElement.getAttribute("animaScaley").toFloat();
        float animaScalez = quadElement.getAttribute("animaScalez").toFloat();
        float animaRotateX = quadElement.getAttribute("animaRotateX").toFloat();
        float animaRotateY = quadElement.getAttribute("animaRotateY").toFloat();

        // Set the animation parameters for the current quad
        quads[i].animaScaley = animaScaley;
        quads[i].animaScalez = animaScalez;
        quads[i].animaRotateX = animaRotateX;
        quads[i].animaRotateY = animaRotateY;
    }
}
