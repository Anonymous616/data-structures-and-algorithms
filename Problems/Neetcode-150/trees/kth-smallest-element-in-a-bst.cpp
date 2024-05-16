// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
  void dfs(TreeNode *node, int k, vector<int> &visited) {
    if (node == NULL)
      return;

    if (visited.size() >= k)
      return;

    dfs(node->left, k, visited);

    visited.push_back(node->val);

    dfs(node->right, k, visited);
  }

  int kthSmallest(TreeNode *root, int k) {
    vector<int> smallest_values;

    dfs(root, k, smallest_values);

    return smallest_values[k - 1];
  }
};
