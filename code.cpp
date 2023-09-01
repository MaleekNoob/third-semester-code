#include <iostream>
using namespace std;



int binary_search(int arr[], int key) {
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = size - 1, mid = (start + end) / 2;

    while(1) {
        if (arr[mid] == key) {
            return mid;
        } 
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else if (start > end) {
            return -1;
        }
    }
}

int main() {
    int arr[] = {2, 4, 5, -6, 0, -2, 8, 3, 9, 1, -3};
    int key = 4;
    cout << "key " << key << " found at index location " << binary_search(arr, key);
}