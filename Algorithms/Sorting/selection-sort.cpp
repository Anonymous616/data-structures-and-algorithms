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

// Selection Sort
vector<int> selectionSort(vector<int> data) {
    int n = data.size();
    int least;

    cout << "Original Data :\t"; printVector(data); cout << "\n";

    for (int i = 0; i < n; i++) {
        least = i;
        for(int j = i+1; j < n; j++)
            if (data[least] > data[j])
                least = j;

        swapInt(&data[i], &data[least]);

        cout << "Iteration " << i + 1 << " :\t"; printVector(data); cout << "\n";
    }

    cout << "Sorted Data :\t"; printVector(data); cout << endl;

    return data;
}

int main() {
    vector<int> data(5, 0); // Initialize vector array of 100 0's
    srand(time(0)); // Use srand() for different outputs
    generate(data.begin(), data.end(), rand); // Generate value using generate

    checkSortTime(data, &selectionSort, "Selection Sort");
}
