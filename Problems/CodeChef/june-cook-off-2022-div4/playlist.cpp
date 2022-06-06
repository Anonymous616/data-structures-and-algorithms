/* https://www.codechef.com/submit-v2/SONGS */
#include<iostream>

using namespace std;

int solve(int n, int x) {
    return n / (3 * x);
}

int main() {

    int t, n, x;

    cin >> t;

    while(t--) {
        cin >> n >> x;
        cout << solve(n, x) << "\n";
    }

    return 0;
}
