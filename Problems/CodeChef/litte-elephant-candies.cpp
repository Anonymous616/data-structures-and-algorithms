/* Problem Statement: https://www.codechef.com/problems/LECANDY */

#include <iostream>
#include <vector>

using namespace std;

string lecandy(int elephants, int candies, vector<int> candies_req) {

    // Iterate through required candies
    for (int candy_req : candies_req) {
        candies -= candy_req; // Get remaining candies

        if (candies < 0) return "No"; // Insufficeint candies
    }

    return "Yes"; // Sufficient changes
}

int main() {

    int test_cases,
        total_elephants,
        total_candies,
        input;
    vector<int> candies_req;

    cin >> test_cases; // Get test cases

    for (int i = 0; i < test_cases; i++) {
        cin >> total_elephants; // Get total elephants
        cin >> total_candies; // Get total candies

        // Get candy preference for all elephants
        for (int j = 0; j < total_elephants; j++) {
            cin >> input;
            candies_req.push_back(input);
        }

        // Calculate answer
        cout << lecandy(total_elephants, total_candies, candies_req) << endl;

        // Remove all elements of the vector
        candies_req.clear();
    }

    return 0;
}

