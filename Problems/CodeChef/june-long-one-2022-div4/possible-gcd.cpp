#include <iostream>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    int n = abs(b - a), res = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i != 0)
            continue;

        if (n / i == i)
            res += 1;
        else
            res += 2;

    }
    return res;
}

int main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << solution(a, b) << "\n";
    }
	return 0;
}
