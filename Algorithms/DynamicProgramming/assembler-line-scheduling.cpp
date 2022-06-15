#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;


pair<vector<string>, int> assemblyLine(vector<vector<int>> a, vector<vector<int>> t,
                    int e[2], int x[2]) {
    vector<string> res = {};

    int N = a[0].size();

    int F[2][N];
    int L[2][N];

    F[0][0] = e[0] + a[0][0];
    F[1][0] = e[1] + a[1][0];

    L[0][0] = -1;
    L[1][0] = -1;

    // Create map
    for (int i = 1; i < N; i++) {

        // Calculate for line 1
        int pathCost1 = F[0][i-1] + a[0][i];
        int pathCost2 = F[1][i-1] + t[1][i-1] + a[0][i];

        if (pathCost2 < pathCost1) {
            F[0][i] = pathCost2;
            L[0][i] = 1;
        } else {
            F[0][i] = pathCost1;
            L[0][i] = 0;
        }

        // Calculate for line 2
        pathCost1 = F[1][i-1] + a[1][i];
        pathCost2 = F[0][i-1] + t[0][i-1] + a[1][i];

        if (pathCost2 < pathCost1) {
            F[1][i] = pathCost2;
            L[1][i] = 1;
        } else {
            F[1][i] = pathCost1;
            L[1][i] = 0;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < N; j++) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < N; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    // Find Path
    int line, cost = 0;

    if (L[0][N-1] + x[0] < L[1][N-1] + x[1]) {
        line = 0;
        cost = L[0][N-1] + x[0];
    } else {
        line = 1;
        cost = L[1][N-1] + x[1];
    }

    res.push_back("A" + to_string(line) + "S" + to_string(N));

    for (int i = N-2; line != -1; i--) {
        line = L[line][i];
        res.push_back("A" + to_string(line) + "S" + to_string(i + 1));
    }

    res.push_back("A" + to_string(L[line][1]) + "S" + to_string(1));

    return pair<vector<string>, int>{res, cost};
}

int main() {
    vector<vector<int>> a = {
        {8, 10, 4, 5, 9},
        {9, 6, 7, 5, 6}
    };
    vector<vector<int>> t = {
        {2, 3, 1, 3},
        {2, 1, 2, 2}
    };
    int e[2] = {3, 5};
    int x[2] = {2, 1};

    pair<vector<string>, int> res = assemblyLine(a, t, e, x);

    cout << "Path" << endl;
    for (auto ele : res.first) {
        cout << ele << " <- ";
    }
    cout << endl;
    cout << "Cost : " << res.second << endl;

    return 0;
}
