#include "testime.cpp"
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> data) {
  for (auto ele : data)
    cout << ele << "\t";
  cout << endl;
}

// Insertion Sort
vector<int> insertionSort(vector<int> data) {
  int n = data.size();
  int key, j;

  cout << "\nOriginal Data :\t";
  printVector(data);

  for (int i = 1; i < n; i++) {
    key = data[i];
    j = i;
    while (j > 0 && data[j - 1] > key) {
      data[j] = data[j - 1];
      j--;
    }
    data[j] = key;

    cout << "\nIteration " << i << " :\t";
    printVector(data);
  }

  cout << "\nSorted Data :\t";
  printVector(data);

  return data;
}

int main() {
  cout << "===== Insertion Sort =====" << endl;
  vector<int> data(5, 0);                   // Initialize vector array of 50 0's
  srand(time(0));                           // Use srand() for different outputs
  generate(data.begin(), data.end(), rand); // Generate value using generate

  insertionSort(data);

  // checkSortTime(data, &insertionSort, "Insertion Sort");
}
