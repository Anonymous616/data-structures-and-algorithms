/* https://www.codechef.com/submit-v2/FIRSTANDLAST */
#include<iostream>
#include<algorithm>

using namespace std;

int solve(int nums[], int n) {
    int res = nums[0] + nums[n - 1];

    for (int i = 0; i < n - 1; i++)
        res = max(res, nums[i] + nums[i+1]);

    return res;
}

int main() {
    int t, n;

    cin >> t;

    while(t--) {
        cin >> n;

        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << solve(nums, n) << "\n";
    }

    return 0;
}
