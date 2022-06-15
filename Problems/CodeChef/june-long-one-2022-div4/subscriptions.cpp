#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int x) {
    return ceil((double) n / 6) * x;
}

int main() {
	int t, n, x;
	cin >> t;
	while(t--) {
	    cin >> n >> x;
	    cout << solution(n, x) << "\n";
	}
	return 0;
}
