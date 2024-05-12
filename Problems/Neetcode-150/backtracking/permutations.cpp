// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> &nums, int start) {
        if (nums.size() == start) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};