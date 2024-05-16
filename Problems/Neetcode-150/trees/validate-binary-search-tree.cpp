// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
  bool dfs(TreeNode *node, long mn, long mx) {
    if (node == NULL)
      return true;

    if (!(node->val > mn && node->val < mx))
      return false;

    return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
  }

  bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }
};
