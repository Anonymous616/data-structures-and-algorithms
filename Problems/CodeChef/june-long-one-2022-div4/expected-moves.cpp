#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

ll solution(ll x, ll n) {
    return (x - 1) * (2 * n - x);
}

int main() {
    ll t, x, n;
    cin >> t;
    while(t--) {
        cin >> x >> n;
        cout << solution(x, n) << "\n";
    }
	return 0;
}
