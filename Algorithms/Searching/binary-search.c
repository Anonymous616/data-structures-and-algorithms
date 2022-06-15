#include<stdio.h>

/*
   ========================
           Binary
   ========================
*/

// Binary Search Iterative
int binary(double arr[], int n, double value) {
    int beg = 0, end = n - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2; // Calculate Mid
        if (arr[mid] == value)
            return mid; // Element found
        else if (arr[mid] < value)
            end = mid - 1; // Search in right sub array
        else
            beg = mid + 1; // Search in left sub array
    }

    return -1; // Element not found
}

// Binary Search Recursive
int binaryRec(double arr[], int beg, int end, double value) {
    int mid = (beg + end) / 2; // Calculate Mid
    if (beg >= end)
        return -1; // Element not found
    else if (arr[mid] == value)
        return mid; // Element found
    else if (arr[mid] < value)
        return binaryRec(arr, mid - 1, end, value); // Search in right sub array
    else
        return binaryRec(arr, beg, mid + 1, value); // Search in left sub array
}

int main() {

    double arr[] = {10, 20, 30, 40, 50};

    // Binary Search
    index = binary(arr, sizeof(arr)/sizeof(arr[0]), 30);
    printf("Binary Search : %d\n", index);
    printf("Binary Search Recursive : %d\n", binaryRec(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, 30)); // Pass beg initially as 0 and end as n - 1

    return 0;
}
