function receiveMessage(callback) {
  // Simulate asynchronous reception of a message
  setTimeout(() => {
    // Call the provided callback function with the received message
    callback("Received message");
  }, 1000);
}
