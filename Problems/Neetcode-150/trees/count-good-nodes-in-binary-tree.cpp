// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
