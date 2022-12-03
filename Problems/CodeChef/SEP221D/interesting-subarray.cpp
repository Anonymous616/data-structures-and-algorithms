#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
typedef long long int ll;
using namespace std;

void solve() {
  int n, x;
  vector<ll> nums;

  cin >> n;

  // Input nums
  for (int i = 0; i < n; i++) {
    cin >> x;
    nums.push_back(x);
  }

  sort(nums.begin(), nums.end());

  ll min = LONG_LONG_MAX;
  ll max = LONG_LONG_MIN;

  max = std::max(nums[n - 1] * nums[n - 1], nums[0] * nums[0]);

  if (nums[0] < 0 && nums[n - 1] < 0) {
    min = nums[0];
  } else {
    min = nums[0] * nums[n - 1];
  }

  cout << min << " " << max << "\n";
}

int main() {
  int no_of_tests;

  cin >> no_of_tests;

  while (no_of_tests--) {
    solve();
  }

  return 0;
}
