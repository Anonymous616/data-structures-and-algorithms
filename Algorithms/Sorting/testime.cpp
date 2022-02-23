#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// Pass your own data to check sorting Time
void checkSortTime(vector<int> data, vector<int> (*func)(vector<int>),
        string const search_name) {
    int n = data.size();

    // Starting Timer
    auto start = high_resolution_clock::now();

    data = func(data);

    // End Timer
    auto stop = high_resolution_clock::now();

    /* for(auto ele: data) cout << ele << "\n"; */

    // Calculate Duration
    auto duration = duration_cast<microseconds>(stop - start);

    // Print out Duration
    cout << "Time taken by " << search_name << " (for " << n << " elements) : "
         << duration.count() << " microseconds" << endl;
}
