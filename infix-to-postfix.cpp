#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

bool IsOperation(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool prcd(char op1, char op2) {
}

string InfixToPostfix(string str) {
    string output = "";
    stack<char> opstk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            if (IsOperation(str[i])) {
                if (prcd(opstk.top(), str[i]))
                    opstk.push(str[i]);
                else
                {
                    char c = opstk.top();
                    opstk.pop();
                    output += c;
                }
            }
            else if (str[i] == '(') {
                opstk.push(str[i]);
            }
            else if (str[i] == ')') {
                while (opstk.top() != '(') {
                    char c = opstk.top();
                    opstk.pop();
                    output += c;
                }
                opstk.pop();
            }
            else
                output += str[i];
        }
    }

    while(!opstk.empty()) {
        char c = opstk.top();
        opstk.pop();
        output += c;
    }

    return output;

}

int main() {
    string str;

    cout << "Enter expression: ";
    getline(cin, str);

    cout << "Postfix expression: " << InfixToPostfix(str) << endl;
}