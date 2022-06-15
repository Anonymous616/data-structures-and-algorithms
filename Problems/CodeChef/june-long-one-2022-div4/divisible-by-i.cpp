#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
}

vector<int> solution(int n) {
    vector<int> res (n, 0);
    int o = 1,
        e = n,
        i = n - 1,
        j = n - 2;

    while (i >= 0) {
        res[i] = e--;
        i -= 2;
    }

    while (j >= 0) {
        res[j] = o++;
        j -= 2;
    }

    return res;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        printVector(solution(n));
    }
	return 0;
}
