javascript
function receiveMessage(callback) {
  // Simulate asynchronous message reception using setTimeout
  setTimeout(() => {
    const message = "Hello, this is the received message!";
    callback(message); // Call the provided callback function with the received message
  }, 1000); // Simulate a delay of 1 second
}

// Example usage of receiveMessage function
function handleMessage(message) {
  console.log("Received message:", message);
}

receiveMessage(handleMessage); // This will output "Received message: Hello, this is the received message!" after a 1-second delay
