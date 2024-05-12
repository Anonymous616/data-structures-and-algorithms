// https://leetcode.com/problems/walls-and-gates/description/
// Free: https://neetcode.io/problems/islands-and-treasure

class Solution {
public:
  static const int INF = 2147483647;
  static const int WATER = -1;
  static const int CHEST = 0;

  void islandsAndTreasure(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != Solution::CHEST)
          continue;

        q.push({i, j});
      }
    }

    vector<pair<int, int>> dirs{
        {-1, 0}, // down
        {1, 0},  // up
        {0, -1}, // left
        {0, 1}   // right
    };

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;

      q.pop();

      for (auto dir : dirs) {
        int i = row + dir.first;
        int j = col + dir.second;

        if (i < 0 || j < 0 || i >= m || j >= n)
          continue;

        if (grid[i][j] != Solution::INF)
          continue;

        grid[i][j] = grid[row][col] + 1;
        q.push({i, j});
      }
    }
  }
};
