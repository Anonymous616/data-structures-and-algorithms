#include <bits/stdc++.h>
#include "testime.cpp"

using namespace std;

// Linear Search Iterative
int linear(vector<int> data, int value) {

    for (int i = 0; i < data.size(); i++)
        if (data[i] == value)
            return i; // Element found

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

    int index = linear(data, value);
    if (index == -1)
        cout << value << " not found" << endl;
    else
        cout << value << " found at " << index << endl;

    checkSearchTime(&linear, 1000, "Linear Search", false);
}