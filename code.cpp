#include <iostream>
using namespace std;

void selection_sort(int arr[], int size) {
    // int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int binary_search(int arr[], int key, int size) {
    int start = 0, end = size - 1, mid = (start + end) / 2;

    while(1) {
        if (arr[mid] == key) {
            return mid;
        } 
        else if(start == end)
        {
            return -1;
        }
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
}

int main() {
    int arr[] = {2, 4, 5, -6, 0, -2, 8, 3, 9, 1, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 99;
    selection_sort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << endl << "At index " << i << ": " << arr[i];
    }
    cout << endl << "key " << key << " found at index location " << binary_search(arr, key, size);
}