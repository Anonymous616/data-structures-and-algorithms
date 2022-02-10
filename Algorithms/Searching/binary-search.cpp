#include <bits/stdc++.h>
#include "testime.cpp"

using namespace std;

// Binary Search Iterative
int binary(vector<int> data, int value) {
    int beg = 0, end = data.size() - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2; // Calculate Mid
        if (data[mid] == value)
            return mid; // Element found
        else if (data[mid] > value)
            end = mid - 1; // Search in right sub
        else
            beg = mid + 1; // Search in left sub
    }

    return -1; // Element not found
}

void print(vector<int> data) {
    for (auto element: data)
        cout << element << "\n";
    cout << endl;
}

int main() {
    vector<int> data = generateRandomIntVectorSorted(10);
    int value = data[rand() % 10];

    cout << "Data: \n";
    print(data);

    cout << "\n ==== Binary Search =====\nElement to find : " << value << endl;

    int index = binary(data, value);
    if (index == -1)
        cout << value << " not found" << endl;
    else
        cout << value << " found at " << index << endl;

    checkSearchTime(&binary, 1000, "Binary Search", true);
}
