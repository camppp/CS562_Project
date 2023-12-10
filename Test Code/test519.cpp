#include <iostream>
#include <cmath>

double novoEmprestimo(double loanAmount, double annualInterestRate, double loanDuration) {
  double monthlyInterestRate = annualInterestRate / 12 / 100;
  double numberOfPayments = loanDuration * 12;
  double monthlyPayment = loanAmount * (monthlyInterestRate * (1 + monthlyInterestRate)^numberOfPayments) / ((1 + monthlyInterestRate)^numberOfPayments - 1);
  return monthlyPayment;
}

int main() {
  double loanAmount = 200;
  double annualInterestRate = 5;
  double loanDuration = 1;
  double monthlyPayment = novoEmprestimo(loanAmount, annualInterestRate, loanDuration);
  std::cout << "Monthly payment: " << monthlyPayment << std::endl;
  return 0;
}
