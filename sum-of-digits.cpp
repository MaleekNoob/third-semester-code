#include <iostream>
using namespace std;

int sum(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sum(num / 10);
}

int main() {
    int num = 12345;
    cout << "Sum of digits in " << num << " is " << sum(num);
    return 0;
}