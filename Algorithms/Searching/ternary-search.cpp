#include <bits/stdc++.h>
#include "testime.cpp"

using namespace std;

// Ternary Search Iterative
int ternary(vector<int> data, int value) {
    int beg = 0, end = data.size() - 1, mid1, mid2;

    while (beg <= end) {
        mid1 = beg + (end -  beg) / 3; // Calculate Mid 1
        mid2 = mid1 + (end - beg) / 3; // Calculate Mid 2
        if (data[mid1] == value)
            return mid1; // Element found
        if (data[mid2] == value)
            return mid2; // Element found
        if (data[mid1] > value)
            end = mid1 - 1; // Search in right sub
        if (data[mid2] < value) {
            beg = mid1 + 1; // Search in left sub
            end = mid2 - 1;
        }
    }

    return -1;
}

void print(vector<int> data) {
    for (auto element: data)
        cout << element << "\n";
    cout << endl;
}

int main() {
    vector<int> data = generateRandomIntVector(10);
    int value = data[rand() % 10];

    cout << "Data: \n";
    print(data);

    cout << "\n ==== Linear Search =====\nElement to find : " << value << endl;

    int index = ternary(data, value);
    if (index == -1)
        cout << value << " not found" << endl;
    else
        cout << value << " found at " << index << endl;

    checkSearchTime(&ternary, 1000, "Ternary Search", true);
}
