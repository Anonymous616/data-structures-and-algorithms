// https://leetcode.com/problems/clone-graph/

class Solution {
public:
  unordered_map<int, Node *> visited;

  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;

    Node *start = new Node(node->val);

    visited[node->val] = start;

    for (int i = 0; i < node->neighbors.size(); i++) {
      Node *neighbor = node->neighbors[i];
      if (visited.count(neighbor->val))
        start->neighbors.push_back(visited[neighbor->val]);
      else
        start->neighbors.push_back(cloneGraph(neighbor));
    }

    return start;
  }
};
