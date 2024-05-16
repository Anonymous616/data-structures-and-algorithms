// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
  void dfs(vector<vector<int>> &heights, int row, int col,
           set<pair<int, int>> &visited, int prevHeight) {
    int m = heights.size(), n = heights[0].size();
    pair<int, int> coords{row, col};

    if (row < 0 || col < 0 || row >= m || col >= n || visited.count(coords) ||
        heights[row][col] < prevHeight) {
      return;
    }

    visited.insert(coords);
    dfs(heights, row, col + 1, visited, heights[row][col]);
    dfs(heights, row, col - 1, visited, heights[row][col]);
    dfs(heights, row + 1, col, visited, heights[row][col]);
    dfs(heights, row - 1, col, visited, heights[row][col]);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    set<pair<int, int>> p, a;

    for (int col = 0; col < n; col++) {
      dfs(heights, 0, col, p, heights[0][col]);
      dfs(heights, m - 1, col, a, heights[m - 1][col]);
    }

    for (int row = 0; row < m; row++) {
      dfs(heights, row, 0, p, heights[row][0]);
      dfs(heights, row, n - 1, a, heights[row][n - 1]);
    }

    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pair<int, int> coords{i, j};
        if (p.count(coords) && a.count(coords)) {
          result.push_back(vector<int>{coords.first, coords.second});
        }
      }
    }

    return result;
  }
};
