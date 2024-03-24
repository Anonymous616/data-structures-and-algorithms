// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
  vector<vector<int>> result;
  void dfs(int start, vector<int> &nums, vector<int> subset) {
    if (start >= nums.size()) {
      result.push_back(subset);
      return;
    }

    int i = start;
    while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
      i++;
    }
    dfs(i + 1, nums, subset);

    subset.push_back(nums[start]);
    dfs(start + 1, nums, subset);
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    dfs(0, nums, vector<int>());
    return result;
  }
};