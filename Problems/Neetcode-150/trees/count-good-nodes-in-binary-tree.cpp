// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
  int dfs(TreeNode *node, int mx) {
    if (node == NULL)
      return 0;

    int is_good_node = 0;
    if (node->val >= mx) {
      mx = max(node->val, mx);
      is_good_node++;
    }

    return is_good_node + dfs(node->left, mx) + dfs(node->right, mx);
  }

  int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }
};
