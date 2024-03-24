// https://leetcode.com/problems/two-sum/

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> memo;
    for (int i = 0; i < nums.size(); i++) {
      const int x1 = nums[i];
      const int x2 = target - nums[i];

      if (memo.count(x2)) {
        return {i, memo[x2]};
      }

      memo[x1] = i;
    }

    return {-1, -1};
  }
};