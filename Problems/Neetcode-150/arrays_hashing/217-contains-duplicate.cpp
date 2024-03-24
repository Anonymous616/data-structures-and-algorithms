// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> numsSet;

    for (int num : nums) {
      if (numsSet.count(num))
        return true;

      numsSet.insert(num);
    }
    return false;
  }
};