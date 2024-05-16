// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
  void dfs(TreeNode *node, int &k, int &result) {
    if (node == NULL)
      return;

    dfs(node->left, k, result);

    if ((--k) == 0) {
      result = node->val;
      return;
    }

    dfs(node->right, k, result);
  }

  int kthSmallest(TreeNode *root, int k) {
    int result;

    dfs(root, k, result);

    return result;
  }
};
