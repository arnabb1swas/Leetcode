class Solution {
  public:
    bool issafe(vector<vector<char>>& board, int row, int col, int n){
        int i = row;
        int j = col;
        
        //FOR ROWS
        while (j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
        j--;
        }
        i = row;
        j = col;
        //FOR UPPER LEFT
        while (i >= 0 && j >= 0){
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row;
        j = col;
        
        //FOR BOTTOM LEFT
        while (i < n && j >= 0){
            if (board[i][j] == 'Q') {
                return false;
            }
            i++; j--;
        }
        
        return true;
    }
    
    void solve(vector<vector<char>>& board, int col, int n, vector<vector<string>>& ans) {
        if (col >= n) {
            vector < string > solution;
            for (int i = 0; i < n; i++) {
                solution.push_back(string(board[i].begin(), board[i].end()));
            }
            ans.push_back(solution);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (issafe(board, row, col, n)) {
                // SOLVING 1 CASE
                board[row][col] = 'Q';
                // RECURSIVE CALL
                solve(board, col + 1, n, ans);
                // BACKTRACKING
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>>solveNQueens(int n) {
        vector<vector<char>>board(n, vector<char> (n, '.'));
        int col = 0;
        vector<vector<string>> ans;
        solve(board, col, n, ans);
        
        return ans;

    }
};