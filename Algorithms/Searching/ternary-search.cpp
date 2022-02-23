#include <bits/stdc++.h>
#include "testime.cpp"

using namespace std;

// Ternary Search Iterative
int ternary(vector<int> data, int beg, int end, int value) {

   if(beg <= end) {
        int mid1 = beg + (end - beg) /3;
        int mid2 = mid1 + (end - beg) /3;
        cout << mid1 << " " << mid2 << endl;

        if(data[mid1] == value)
            return mid1; // Found

        if(data[mid2] == value)
            return mid2; // Found

        // Check in left sub
        if(data[mid1] > value)
            return ternary(data, beg, mid1 - 1, value);

        // Check in right sub
        if(data[mid2] < value)
            return ternary(data, mid2 + 1, end, value);

        return ternary(data, mid1 + 1, mid2 - 1, value);
   }

    return -1;
}

void print(vector<int> data) {
    for (auto element: data)
        cout << element << "\n";
    cout << endl;
}

int main() {
    vector<int> data = generateRandomIntVectorSorted(11);
    int value = data[rand() % 11];

    cout << "Data: \n";
    print(data);

    cout << "\n ==== Ternary Search =====\nElement to find : " << value << endl;

    int index = ternary(data, 0, data.size()-1, value);
    if (index == -1)
        cout << value << " not found" << endl;
    else
        cout << value << " found at " << index << endl;

    /* checkSearchTime(&ternary, 1000, "Ternary Search", true); */
}
