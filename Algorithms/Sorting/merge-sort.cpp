#include "testime.cpp"
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> data) {
  for (auto ele : data)
    cout << ele << "\t";
  cout << endl;
}

void merge(vector<int>& v, int low, int mid, int high) {

	vector<int> temp;

	int i = low, j = mid + 1;

	while (i <= mid && j <= high)
        temp.push_back(v[i] <= v[j] ? v[i++] : v[j++]);

	while (i <= mid)
		temp.push_back(v[i++]);

	while (j <= high)
		temp.push_back(v[j++]);

	for (i = low; i <= high; ++i)
		v[i] = temp[i - low];
}

void mergeSort(vector<int>& data, int low, int high) {
	if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(data, low, mid);
    mergeSort(data, mid + 1, high);
    merge(data, low, mid, high);

    cout << "\nMerge :\n";
    printVector(data);
    cout << endl;
}

void mergeSort(vector<int> data) {
  int n = data.size();

  cout << "Original Data :\n";
  printVector(data);

  mergeSort(data, 0, n - 1);

  cout << "\nSorted Data :\n";
  printVector(data);
  cout << endl;

}

int main() {
  cout << "===== Merge Sort =====" << endl;

  vector<int> data(6, 0);                   // Initialize vector array of 50 0's
  srand(time(0));                           // Use srand() for different outputs
  generate(data.begin(), data.end(), rand); // Generate value using generate

  mergeSort(data);

  // checkSortTime(data, &mergeSort, "Merge Sort");
}
