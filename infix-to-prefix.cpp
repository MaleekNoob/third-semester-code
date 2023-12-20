#include <iostream>
#include <stack>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

std::string infixToPrefix(const std::string& infix) {
    std::string prefix;
    std::stack<char> stack;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isOperator(c)) {
            while (!stack.empty() && getPrecedence(stack.top()) > getPrecedence(c)) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(c);
        } else if (c == ')') {
            stack.push(c);
        } else if (c == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            prefix += c;
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string prefixExpression = infixToPrefix(infixExpression);
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
