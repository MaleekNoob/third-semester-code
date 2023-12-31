#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int prec(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') { // if operand
            res += s[i];
        }
        else if (s[i] == '(') { // if opening bracket
            st.push(s[i]);
        }
        else if (s[i] == ')') { // if closing bracket
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else { // if operator
            while (!st.empty() && prec(st.top()) > prec(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(s) << endl;
    return 0;
}