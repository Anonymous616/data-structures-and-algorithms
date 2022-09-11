/* https://www.codechef.com/COOK142D/problems/SPLITANDSUM */
#include<iostream>
#include<vector>
#define ll long long
using namespace std;

void solve(ll arr[], ll n) {
    for (ll i = 0; i < 30; i++) {
        ll x = 1 << i;
        vector<ll> v = {0};

        for (ll j = 0; j < n; j++)
            if (arr[j] & x) v.push_back(j + 1);

        if (v.size() > 2) {
            v.back() = n;

            cout << "YES\n" << v.size() - 1 << "\n";

            for (ll j = 1; j < v.size(); j++)
                cout << v[j-1] + 1 << " " << v[j] << "\n";

            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        ll a[n];

        for (ll i = 0; i < n; i++)
            cin >> a[i];

        solve(a, n);
    }

    return 0;
}
