javascript
function novoEmprestimo(loanAmount, annualInterestRate, loanDuration) {
  const monthlyInterestRate = annualInterestRate / (12 * 100);
  const numberOfPayments = loanDuration * 12;
  
  const monthlyPayment = loanAmount * monthlyInterestRate * Math.pow(1 + monthlyInterestRate, numberOfPayments) / (Math.pow(1 + monthlyInterestRate, numberOfPayments) - 1);
  
  return monthlyPayment.toFixed(2);
}

// Test
console.log(novoEmprestimo(200, 5, 1)); // Output: 17.30
