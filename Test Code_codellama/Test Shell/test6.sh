List<String> resizeImages(List<String> imageDimensions, int max) {
    List<String> resizedDimensions = new ArrayList<>();
    for (String imageDimension : imageDimensions) {
        int width = Integer.parseInt(imageDimension.split("x")[0]);
        int height = Integer.parseInt(imageDimension.split("x")[1]);
        if (width > max || height > max) {
            int newWidth = width > max ? max : width;
            int newHeight = height > max ? max : height;
            resizedDimensions.add(newWidth + "x" + newHeight);
        } else {
            resizedDimensions.add(imageDimension);
        }
    }
    return resizedDimensions;
}