// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> yaxes(9);
        vector<unordered_set<int>> xaxes(9);
        vector<unordered_set<int>> squares(9);

        // i = y-axis, j = x-axis
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;

                cout << (i / 3) * 3 + j / 3 << " ";

                if (xaxes[j].count(board[i][j]) 
                    || yaxes[i].count(board[i][j]) 
                    || squares[(i / 3) * 3 + j / 3].count(board[i][j])) {
                        return false;
                    }

                xaxes[j].insert(board[i][j]); 
                yaxes[i].insert(board[i][j]); 
                squares[(i / 3) * 3 + j / 3].insert(board[i][j]); 
            }
        }

        return true;
    }
};