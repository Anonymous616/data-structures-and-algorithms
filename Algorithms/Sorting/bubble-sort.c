#include<stdio.h>

void swap(double *x,double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

/*
   ========================
           Bubble
   ========================
*/

double* bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - i - 1; j ++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);

        }
    }
    return arr;
}

void print(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%0.3lf ", arr[i]);
    }
    printf("\n");
}

int main() {

    double arr[] = {30, 21, 43, 23, 69, 102, 49, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);
    swap(&arr[2], &arr[3]);

    double *bubble = bubbleSort(arr, n);
    print(bubble, n);

    return 0;
}
