public static String getInputFileName(Configuration conf) {
    if (conf == null) {
        return "";
    }
    String inputFileName = conf.getInputFileName();
    if (inputFileName == null || inputFileName.isEmpty()) {
        return "";
    }
    return inputFileName;
}