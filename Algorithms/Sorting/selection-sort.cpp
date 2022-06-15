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

// Selection Sort
vector<int> selectionSort(vector<int> data) {
  int n = data.size();
  int least;

  cout << "\nOriginal Data :\t";
  printVector(data);

  for (int i = 0; i < n - 1; i++) {
    least = i;
    for (int j = i + 1; j < n; j++)
      if (data[least] > data[j])
        least = j;

    swapInt(&data[i], &data[least]);

    cout << "\nIteration " << i + 1 << " :\t";
    printVector(data);
  }

  cout << "\nSorted Data :\t";
  printVector(data);

  return data;
}

int main() {
  cout << "===== Selection Sort =====" << endl;

  vector<int> data(5, 0);                   // Initialize vector array of 50 0's
  srand(time(0));                           // Use srand() for different outputs
  generate(data.begin(), data.end(), rand); // Generate value using generate

  selectionSort(data);

  // checkSortTime(data, &selectionSort, "Selection Sort");
}
