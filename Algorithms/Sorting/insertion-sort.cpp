#include<bits/stdc++.h>
#include "testime.cpp"

using namespace std;

void printVector(vector<int> data) {
    for (auto ele : data) cout << ele << "\t";
}

// Insertion Sort
vector<int> insertionSort(vector<int> data) {
    int n = data.size();
    int key, j;

    cout << "Original Data :\t"; printVector(data); cout << "\n";

    for (int i = 1; i < n; i++) {
        key = data[i];
        j = i;
        while (j>0 && data[j-1]>key) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = key;

        cout << "Iteration " << i << " :\t"; printVector(data); cout << "\n";
    }

    cout << "Sorted Data :\t"; printVector(data); cout << endl;

    return data;
}

int main() {
    vector<int> data(5, 0); // Initialize vector array of 100 0's
    srand(time(0)); // Use srand() for different outputs
    generate(data.begin(), data.end(), rand); // Generate value using generate

    checkSortTime(data, &insertionSort, "Insertion Sort");
}
