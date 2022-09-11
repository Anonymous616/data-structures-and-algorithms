/* https://www.codechef.com/COOK142D/problems/TWONUMBERS */
#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

ll solve(ll n) {
    if (n == 2)
        return 0;

    if (n % 2 == 0)
        if ((n / 2 - 1) % 2 == 1)
            return ((n/2 - 1) * (n/2 + 1)) - 1;
        else
            return ((n/2 - 2) * (n/2 + 2)) - 1;

    return ((n-1)/2 * (n+1)/2) - 1;
}

int main() {
    int t;
    ll n;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}
