#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

void bubble_sort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - i) - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

}

void selection_sort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertion_sort(int arr[], int size) {

    int i, j;
    for (i = 1; i < size; i++) {
        int temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int gettime() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

int main() {

    int arr[100000];

    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100000;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    uint64_t start, end;

    start = gettime();
    insertion_sort(arr, size);
    end = gettime();

    // for (int num: arr) {
    //     cout << num << endl;
    // }

    cout << "Time taken: " << end - start << " micro seconds" << endl;

    return 0;
}