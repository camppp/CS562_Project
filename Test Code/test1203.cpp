javascript
function simulateTapeOperations(arr) {
  const tape = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < 0) {
      tape.pop();
      if (tape.length === 0) break;
    } else {
      tape.push(arr[i]);
    }
  }
  return tape;
}

// Test the function
console.log(simulateTapeOperations([5, -2, 7, -3, 1])); // Output: [5, 1]
console.log(simulateTapeOperations([3, -1, 4, 2, -5, 6])); // Output: [3, 4, 6]
