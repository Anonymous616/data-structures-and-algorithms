/* https://www.codechef.com/submit-v2/BREAKSTICK */
#include <iostream>
using namespace std;

string solve(int n, int x) {
    if (n % 2 == 0 || x % 2 == 1)
        return "YES";
    return "NO";
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
