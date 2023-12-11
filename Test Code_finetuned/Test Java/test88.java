public String getSourceDirectory(String filename) {
    if (fileUriMap.containsKey(filename)) {
        URI uri = fileUriMap.get(filename);
        String src = new File(uri.getPath()).getParentFile().getAbsolutePath();
        return src;
    }
    return null;
}