java
public void processAndExportModel(String s, int lr, int lt, boolean gb, String lbr, String lbt, boolean needCreateJoints, Exporter exporter, Model model, double radius) {
    // Compute the RTB
    computeRTB(s, lr, lt, gb, lbr, lbt);

    // Create joints if necessary
    if (needCreateJoints) {
        exporter.createJoints(model.boneName, model.parent, radius);
    }

    // Export the model
    exporter.exportModel(model);
}
