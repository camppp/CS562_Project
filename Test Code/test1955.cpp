function extractValue(document) {
    if (document.hasOwnProperty("machineHash")) {
        return document.machineHash;
    } else if (document.hasOwnProperty("payload")) {
        return document.payload;
    } else {
        return null;
    }
}
