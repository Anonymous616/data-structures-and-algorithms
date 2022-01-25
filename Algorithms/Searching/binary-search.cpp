#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// Binary Search Iterative
int binary(vector<int> data, int value) {
    int beg = 0, end = data.size() - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2; // Calculate Mid
        if (data[mid] == value)
            return mid; // Element found
        else if (data[mid] < value)
            end = mid - 1; // Search in right sub
        else
            beg = mid + 1; // Search in left sub
    }

    return -1; // Element not found
}


void print(vector<int> data) {
    for (auto element: data)
        cout << element << " ";
    cout << endl;
}

vector<int> generateRandomIntVector(int n) {
    vector<int> data(n, 0); // Initialize vector array
    srand(time(0)); // Use srand() for different outputs
    generate(data.begin(), data.end(), rand); // Generate value using generate
    return data;
}

vector<int> generateRandomIntVectorSorted(int n) {
    vector<int> data(n, 0); // Initialize vector array
    srand(time(0)); // Use srand() for different outputs
    generate(data.begin(), data.end(), rand); // Generate value using generate
    sort(data.begin(), data.end(), greater<int>()); // Sort vector
    return data;
}

void checkSearchTime(int (*func)(vector<int>, int), int iterations, string const search_name) {
    int res, n = 100;
    vector<int> data = generateRandomIntVectorSorted(n); // 100 Elements vector

    int value;

    // Starting Timer
    auto start = high_resolution_clock::now();

    for(int i = 0; i < iterations; i++) {
        value = data[rand() % n]; // Get random value
        res = func(data, value); // Call search function to test
    }

    // End Timer
    auto stop = high_resolution_clock::now();

    // Calculate Duration
    auto duration = duration_cast<microseconds>(stop - start);

    // Print out Duration
    cout << "Time taken by " << search_name << " (for " << iterations << " iterations) : "
         << duration.count() << " microseconds" << endl;
}

int main() {
    vector<int> data = generateRandomIntVectorSorted(10);
    int value;

    cout << "Vector: \n" << print(data);

    cout << " === Binary Search === " << endl;
    cout << "Enter value to find : ";
    cin >> value;

    int index = binary(data, value);
       if (index == -1)
        cout << value << " not found" << endl;
    else
        cout << value << " found at " << index;

    // checkSearchTime(&binary, 1000, "Binary Search");
}
