#include <stdio.h>

void printData(int *data, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", data[i]);
  printf("\n");
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int *data, int low, int high) {

  int pivot = data[high];

  printf("\nPivot : %d\n", pivot);

  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (data[j] <= pivot) {
      i++;
      swap(data + i, data + j);
      printData(data, 6);
    }
  }

  swap(data + (i + 1), data + high);
  printData(data, 6);

  return i + 1;
}

void quickSort(int *data, int low, int high) {
  if (low < high) {
    int pi = partition(data, low, high);
    quickSort(data, low, pi - 1);
    quickSort(data, pi + 1, high);
  }
}

void quickSort(int *data, int n) { quickSort(data, 0, n - 1); }

int main() {
  int data[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(data) / sizeof(data[0]);

  quickSort(data, n);

  printData(data, n);
}