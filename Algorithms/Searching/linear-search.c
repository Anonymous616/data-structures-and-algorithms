#include<stdio.h>

/*
   ========================
           Linear
   ========================
*/

// Linear Search Iterative
int linear(double arr[], int n, double value) {

    for (int i = 0; i < n; i++)
        if (arr[i] == value)
            return i; // Element found

    return -1;
}

// Linear Search Recursive
int linearRec(double arr[], int n, double value) {
    if (n == 0)
        return -1; // Element not found
    else if (arr[n-1] == value)
        return n-1; // Element found
    else
        return linearRec(arr, n-1, value); // Search next index
}

int main() {

    double arr[] = {10, 20, 30, 40, 50};

    // Linear Search
    int index = linear(arr, sizeof(arr)/sizeof(arr[0]), 30);
    printf("Linear Search : %d\n", index);
    printf("Linear Search Recursive : %d\n", linearRec(arr, sizeof(arr)/sizeof(arr[0]), 30));

    return 0;
}
