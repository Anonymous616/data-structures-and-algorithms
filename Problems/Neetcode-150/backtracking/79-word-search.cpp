class Solution {
public:
  bool dfs(vector<vector<char>> &board, string word, int index, int i, int j) {
    const int ROWS = board.size(), COLS = board[0].size();

    if (i < 0 || i >= ROWS || j < 0 || j >= COLS ||
        board[i][j] != word[index]) {
      return false;
    }
    if (index == word.size() - 1) {
      return true;
    }

    board[i][j] = '#';

    if (dfs(board, word, index + 1, i - 1, j) ||
        dfs(board, word, index + 1, i + 1, j) ||
        dfs(board, word, index + 1, i, j - 1) ||
        dfs(board, word, index + 1, i, j + 1)) {
      return true;
    }

    board[i][j] = word[index];
    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    const int ROWS = board.size(), COLS = board[0].size();

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (board[i][j] != word[0])
          continue;

        if (dfs(board, word, 0, i, j))
          return true;
      }
    }

    return false;
  }
};
