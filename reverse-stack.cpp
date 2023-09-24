#include <iostream>
#include <stack>
using namespace std;

void InsertAtBottom(stack<int> &St, int value) {
    if (St.empty()) {
        St.push(value);
        return;
    }
    int temp = St.top();
    St.pop();
    InsertAtBottom(St, value);
    St.push(temp);
}

class Solution {
public:
    void Reverse(stack<int> &St) {
        if (St.empty()) {
            return;
        }
        int temp = St.top();
        St.pop();
        Reverse(St);
        InsertAtBottom(St, temp);
    }
};

int main() {


    return 0;
}