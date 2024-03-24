// https://leetcode.com/problems/combination-sum/

class Solution {
public:
  vector<vector<int>> result;

  void dfs(int i, vector<int> &nums, vector<int> subset, int target) {
    int sum = accumulate(subset.begin(), subset.end(), 0);

    if (sum == target) {
      result.push_back(subset);
      return;
    }

    if (i >= nums.size() || sum > target) {
      return;
    }

    dfs(i + 1, nums, subset, target);

    int temp_sum = sum;

    while (temp_sum <= target) {
      temp_sum += nums[i];
      subset.push_back(nums[i]);
      dfs(i + 1, nums, subset, target);
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    this->dfs(0, candidates, vector<int>(), target);

    return result;
  }
};