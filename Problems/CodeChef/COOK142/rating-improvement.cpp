/* https://www.codechef.com/COOK142D/problems/ADVANCE */
#include <iostream>
using namespace std;

string solve(int x, int y) {
    int upper = x + 200;
    return (upper >=  y && y >= x) ? "YES" : "NO";
}

int main() {
	int t, x, y;

	cin >> t;

    while(t--) {
	    cin >> x >> y;
	    cout << solve(x, y) << "\n";
	}

	return 0;
}

