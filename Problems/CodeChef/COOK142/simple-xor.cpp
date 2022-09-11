/* https://www.codechef.com/submit-v2/SIMPLE_XOR */
#include<iostream>
using namespace std;
typedef long long int ll;

void solution(ll l, ll r) {
    if (l & 1) l++;

    if (l + 3 <= r)
        cout << l << " " << l+1 << " " << l+2 << " " << l+3 << "\n";
    else
        cout << -1 << "\n";
}

int main() {
    int t;
    ll l, r;

    cin >> t;
    while(t--) {
        cin >> l >> r;
        solution(l, r);
    }

    return 0;
}
