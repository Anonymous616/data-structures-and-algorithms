// https://leetcode.com/problems/subsets/

class Solution {
public:
  vector<vector<int>> result;

  void dfs(int i, vector<int> &nums, vector<int> subset) {
    if (i >= nums.size()) {
      result.push_back(subset);
      return;
    }

    dfs(i + 1, nums, subset);

    subset.push_back(nums[i]);
    dfs(i + 1, nums, subset);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    this->dfs(0, nums, vector<int>());

    return result;
  }
};