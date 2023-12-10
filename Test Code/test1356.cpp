java
public void processAndExportModel(String s, int lr, int lt, boolean gb, String lbr, String lbt, boolean needCreateJoints, Exporter exporter, Model model, double radius) {
    model.computeRTB(s, lr, lt, gb, lbr, lbt); // Call the computeRTB function with the given parameters

    if (needCreateJoints) {
        exporter.createJoints(model.boneName, model.parent, radius); // Call createJoints if needCreateJoints is true
    }
}
