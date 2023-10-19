#include <iostream>
#include <math.h>
using namespace std;

void validate(float &num) {
    while (num < 0 || num >= 1) {
        cout << "\nEnter number in range of (0 - 1): ";
        cin >> num;
    }
}

const int SIZE = 10;

int main() {
    float arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter value: ";
        cin >> arr[i];
        validate(arr[i]);
    }

    float sortArr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        int index = floor(arr[i] * SIZE);
        sortArr[index] = arr[i];
    }

    cout << endl << "Sorted Array: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = sortArr[i];
        cout << arr[i] << " ";
    }
}