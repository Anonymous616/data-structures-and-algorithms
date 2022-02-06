#include <bits/stdc++.h>
#include "testime.cpp"

using namespace std;

void swapInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printVector(vector<int> data) {
    for (auto ele : data) cout << ele << "\t";
}

// Bubble Sort
vector<int> bubbleSort(vector<int> data) {
    int n = data.size();
    bool swapped;

    cout << "Original Data :\t"; printVector(data); cout << "\n";

    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (data[j] > data[j+1]) {
               swapInt(&data[j], &data[j+1]);
               swapped = true;
            }
        }

        cout << "Iteration " << i + 1 << " :\t"; printVector(data); cout << "\n";

        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }

    cout << "Sorted Data :\t"; printVector(data); cout << endl;

    return data;
}

int main() {
    vector<int> data(5, 0); // Initialize vector array of 100 0's
    srand(time(0)); // Use srand() for different outputs
    generate(data.begin(), data.end(), rand); // Generate value using generate

    checkSortTime(data, &bubbleSort, "Improved Bubble Sort");
}
