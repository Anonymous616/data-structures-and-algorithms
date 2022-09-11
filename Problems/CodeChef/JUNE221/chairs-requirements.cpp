#include <iostream>
using namespace std;

int solution(int x, int y) {
    return x < y ? 0 : x - y;
}

int main() {

	int t, x, y;
	cin >> t;

	while(t--) {
	    cin >> x >> y;
	    cout << solution(x,y) << "\n";
	}

	return 0;
}
