#include "testime.cpp"
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> data) {
  for (auto ele : data)
    cout << ele << "\t";
  cout << endl;
}

// Quick Sort
int partition(vector<int> &data, int low, int high) {
  int pivot = data[high];

  cout << "\nPivot : " << pivot << endl;

  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (data[j] < pivot) {
      i++;
      swap(data[i], data[j]);
      printVector(data);
    }
  }

  printVector(data);

  return i + 1;
}

void quickSort(vector<int> &data, int low, int high) {
  if (low < high) {
    int partIndex = partition(data, low, high);
    quickSort(data, low, partIndex - 1);
    quickSort(data, partIndex + 1, high);
  }
}

vector<int> quickSort(vector<int> data) {
  int n = data.size();
  int pivot, j;

  cout << "Original Data :\n";
  printVector(data);

  quickSort(data, 0, n - 1);

  cout << "\nSorted Data :\n";
  printVector(data);
  cout << endl;

  return data;
}

int main() {
  cout << "===== Quick Sort =====" << endl;

  vector<int> data(5, 0);                   // Initialize vector array of 50 0's
  srand(time(0));                           // Use srand() for different outputs
  generate(data.begin(), data.end(), rand); // Generate value using generate

  quickSort(data);

  // checkSortTime(data, &quickSort, "Quick Sort");
}
