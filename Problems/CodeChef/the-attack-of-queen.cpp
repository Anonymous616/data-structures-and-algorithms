/* Problem Statement: https://www.codechef.com/MAY221D/problems/QUEENATTACK */

#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x < y ? x : y;
}

int queenAttack(int n, int x, int y) {

    int noSq = 2*(n-1) +
        min(x-1, y-1) +
        min(n-x, y-1) +
        min(x-1, n-y) +
        min(n-x, n-y);

    return noSq;
}

int main() {

    int test_cases, n, x, y;
    vector<int> res;

    cin >> test_cases; // Get test cases

    for (int i = 0; i < test_cases; i++) {
        cin >> n;
        cin >> x;
        cin >> y;

        res.push_back(queenAttack(n, x, y));
    }

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}
