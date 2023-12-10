class Calculator {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (operators.top() != '(') {
                    operands.push(operators.top());
                    operators.pop();
                }
                operators.pop();
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)) {
                    operands.push(operators.top());
                    operators.pop();
                }
                operators.push(c);
            } else {
                operands.push(c - '0');
            }
        }

        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();
            if (op == '+' || op == '-') {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                operands.push(a + b);
            } else if (op == '*' || op == '/') {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                operands.push(a * b);
            }
        }

        return operands.top();
    }

    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        } else {
            return 0;
        }
    }
};
