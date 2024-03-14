#include<stdio.h>

// Heap is a complete binary tree. Any given node is
// - Always greater than its children (MAX Heap)
// - Always smaller than its children (MIN Heap)

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Heap operations
// - Heapify: Creating a heap data structure from a binary tree
void heapify(int *heap, int size, int i) {
  if (size == 1) {
    return;
  }

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && heap[left] > heap[largest]) {
    largest = left;
  }

  if (right < size && heap[right] > heap[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&heap[i], &heap[largest]);
    heapify(heap, size, largest);
  }
}

void print(int *heap, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", heap[i]);
  }
  printf("\n");
}

void insert(int *heap, int *size, int num) {
  if ((*size) == 0) {
    heap[0] = num;
    (*size)++;
    return;
  } 

  heap[(*size)++] = num;
  for (int i = *size / 2 - 1; i >= 0; i--) {
    heapify(heap, *size, i);
  }
}

void delete(int *heap, int *size, int num) {
  if (size == 0) return;

  int i = 0;
  for (i = 0; i < (*size); i++) {
    if (heap[i] == num) break;
  }

  swap(&heap[i], &heap[--(*size)]);

  for (int i = (*size) / 2 - 1; i >= 0; i--) {
    heapify(heap, *size, i);
  }
}

int main() {
  int heap[10], size = 0;

  insert(heap, &size, 3);
  print(heap, size);

  insert(heap, &size, 4);
  print(heap, size);

  insert(heap, &size, 2);
  print(heap, size);

  delete(heap, &size, 4);
  print(heap, size);

  return 0;
}
