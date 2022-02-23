#include "testime.cpp"
#include <bits/stdc++.h>

using namespace std;

void swapInt(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void printVector(vector<int> data) {
  for (auto ele : data)
    cout << ele << "\t";
  cout << endl;
}

// Bubble Sort
vector<int> bubbleSort(vector<int> data) {
  int n = data.size();

  cout << "\nOriginal Data :\t";
  printVector(data);

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (data[j] > data[j + 1])
        swapInt(&data[j], &data[j + 1]);
    }

    cout << "\nIteration " << i + 1 << " :\t";
    printVector(data);
  }

  cout << "\nSorted Data :\t";
  printVector(data);

  return data;
}

int main() {
  cout << "===== Bubble Sort =====" << endl;

  vector<int> data(5, 0);                   // Initialize vector array of 50 0's
  srand(time(0));                           // Use srand() for different outputs
  generate(data.begin(), data.end(), rand); // Generate value using generate

  bubbleSort(data);

  // checkSortTime(data, &bubbleSort, "Bubble Sort");
}
