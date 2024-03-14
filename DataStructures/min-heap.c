#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(int *heap, int size, int i) {
  if (size == 1 || i > size) return;

  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && heap[left] < heap[smallest])
    smallest = left;

  if (right < size && heap[right] < heap[smallest])
    smallest = right;

  if (smallest != i) {
    swap(&heap[i], &heap[smallest]);
    heapify(heap, size, smallest);
  }
}

void insert(int *heap, int *size, int num) {
  heap[(*size)++] = num;

  if ((*size) == 1) return;

  for (int i = (*size) / 2 - 1; i >= 0; i--)
    heapify(heap, *size, i);
}

void delete(int *heap, int *size, int num) {
  bool found = false;
  int i = -1;

  for (i = 0; i < *size; i++) {
    if (heap[i] == num) {
      found = true;
      break;
    }
  }

  if (!found) return;

  swap(&heap[i], &heap[--(*size)]);

  for (int i = (*size) / 2 - 1; i >= 0; i--) {
    heapify(heap, *size, i);
  }
}

void print(int *heap, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", heap[i]);

  printf("\n");
}

int main() {
  int heap[10], size = 0;

  insert(heap, &size, 6);
  print(heap, size);
  
  insert(heap, &size, 5);
  print(heap, size);

  insert(heap, &size, 2);
  print(heap, size);

  delete(heap, &size, 6);
  print(heap, size);

  return 0;
}
