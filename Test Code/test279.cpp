class BarcodeScanner {
  constructor() {
    this.defaultID = null;
  }

  getDefaultID(params) {
    return this.defaultID;
  }

  setDefaultID(params) {
    this.defaultID = params[0];
  }

  enumerate(id, params) {
    // Interact with JSON data
    const jsonData = JSON.parse(params[0]);
    const barcodeData = jsonData[id];
    return barcodeData;
  }
}
