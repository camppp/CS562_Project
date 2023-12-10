#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Provide an operation and two values you'd like operated on:\n";
    string operatus;
    double val1;
    double val2;
    cin >> operatus >> val1 >> val2;

    double result = 0;
    if (operatus == "+" || operatus == "plus")
        result = val1 + val2;
    else if (operatus == "-" || operatus == "minus")
        result = val1 - val2;
    else if (operatus == "*" || operatus == "times")
        result = val1 * val2;
    else if (operatus == "/" || operatus == "divided" || operatus == "over")
    {
        if (val2 != 0)  // Check for division by zero
            result = val1 / val2;
        else
            cout << "Error: Division by zero is not allowed." << endl;
    }
    else
        cout << "Error: Invalid operation." << endl;

    if (operatus == "+" || operatus == "plus" || operatus == "-" || operatus == "minus" || operatus == "*" || operatus == "times" || (operatus == "/" && val2 != 0))
        cout << "Result: " << result << endl;

    return 0;
}
