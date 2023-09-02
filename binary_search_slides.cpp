// numElems – maximum number of elements in the array
// value – integer data (item) to be searched
// position – array subscript that holds value (if success)
// -1 if value not found
#include <iostream>
using namespace std;

int binarySearch(int array[], int numelems, int value)
{
    int first = 0, last = numelems - 1, middle, position = -1;
    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate mid point
        if (array[middle] == value)
        { // If value is found at mid
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return position;
}

int main() {

    int arr[] = {2, 4, 5, -6, 0, -2, 8, 3, 9, 1, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    int position = binarySearch(arr, size, key);
    if (position == -1) {
        cout << "key " << key << " not found";
    }
    else {
        cout << "key " << key << " found at index location " << position;
    }

    return 0;
}