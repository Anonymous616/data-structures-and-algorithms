class Solution {
public:
   
    unordered_set<int> cols;
    unordered_set<int> left_diag;
    unordered_set<int> right_diag;
    
    void dfs(int n, int row, vector<vector<string>>& res, vector<string>& board){
        if(row == n){
            res.push_back(board);
            return ; 
        }
        
        for(int col = 0; col < n; col++){
            if(
                cols.find(col) != cols.end() ||
                left_diag.find(row - col) != left_diag.end() ||
                right_diag.find(row + col) != right_diag.end()
              )
                continue;
            
            cols.insert(col);
            left_diag.insert(row - col);
            right_diag.insert(row + col);
            board[row][col] = 'Q';
            
            dfs(n, row + 1, res, board);
            
            cols.erase(col);
            left_diag.erase(row - col);
            right_diag.erase(row + col);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        dfs(n, 0, res, board);
        return res;
    }
};
