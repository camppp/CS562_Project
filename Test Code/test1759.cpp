javascript
function isBalancedParentheses(str) {
  const stack = [];
  const opening = '(';
  const closing = ')';
  
  for (let char of str) {
    if (char === opening) {
      stack.push(char);
    } else if (char === closing) {
      if (stack.length === 0) {
        return false; // More closing parentheses than opening ones
      } else {
        stack.pop();
      }
    }
  }
  
  return stack.length === 0; // If stack is empty, all parentheses are balanced
}

// Test cases
console.log(isBalancedParentheses("()")); // Output: true
console.log(isBalancedParentheses("()()")); // Output: true
console.log(isBalancedParentheses("(()")); // Output: false
console.log(isBalancedParentheses("())(")); // Output: false
