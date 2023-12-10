int calcular(int a, int b, char operador) {
    int result;
    switch (operador) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                // Handle division by zero error
                result = 0; // You can choose an appropriate value or handle the error as per requirements
            }
            break;
        default:
            // Handle invalid operator error
            result = 0; // You can choose an appropriate value or handle the error as per requirements
    }
    return result;
}
