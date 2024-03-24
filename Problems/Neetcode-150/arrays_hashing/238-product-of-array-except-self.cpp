// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> result(nums.size(), 1);

    // Find prefix
    int prod = 1;
    for (int i = 0; i < nums.size(); i++) {
      result[i] = prod;
      prod *= nums[i];
    }

    // Find suffix
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      result[i] *= prod;
      prod *= nums[i];
    }

    return result;
  }
};