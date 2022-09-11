#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;


ll solution(ll a, ll b) {
    if (a == 0 && b == 0)
        return 0;

    if (a == 0 || b == 0)
        return -1;

    if (a == b)
        return a;

    ll mn = min(a, b);
    ll mx = max(a, b);

    ll res = 0;
    while (mn < mx) {
        mn *= 2;
        res ++;
    }

    return res + mx;
}

int main() {
    ll t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << solution(a, b) << "\n";
    }
	return 0;
}

