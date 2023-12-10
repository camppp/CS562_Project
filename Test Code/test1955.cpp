javascript
function extractValue(document) {
    if (document.hasOwnProperty("machineHash")) {
        return document["machineHash"];
    } else if (document.hasOwnProperty("payload")) {
        isEntitlementsV3 = true;
        return document["payload"];
    } else {
        return null;
    }
}
