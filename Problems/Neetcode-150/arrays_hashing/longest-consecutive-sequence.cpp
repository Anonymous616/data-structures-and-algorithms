// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> numsSet(nums.begin(), nums.end());

    int longest = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (!numsSet.count(nums[i] - 1)) {
        int length = 1;
        int num = nums[i] + 1;
        while (numsSet.count(num)) {
          length++;
          num++;
        }
        longest = max(longest, length);
      }
    }

    return longest;
  }
};