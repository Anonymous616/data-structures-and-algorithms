// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
  vector<vector<int>> result;

  void dfs(int start, vector<int> &nums, vector<int> subset, int target) {
    int sum = accumulate(subset.begin(), subset.end(), 0);

    if (sum == target) {
      result.push_back(subset);
      return;
    }

    if (start >= nums.size() || sum > target) {
      return;
    }

    int i = start;
    while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
      i++;
    }
    dfs(i + 1, nums, subset, target);

    subset.push_back(nums[start]);
    dfs(start + 1, nums, subset, target);
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    this->dfs(0, candidates, vector<int>(), target);

    return result;
  }
};