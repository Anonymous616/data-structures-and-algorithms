#include <iostream>
#include <unordered_set>
using namespace std;

int solution(string a, string b, int n) {
    unordered_set<char> chars;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;

        chars.insert(b[i]);
    }

    return chars.size();
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> n >> a >> b;
        cout << solution(a, b, n) << "\n";
    }
	return 0;
}
