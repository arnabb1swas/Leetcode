class Solution {
public:
        unordered_map<int,bool> rowCheck;
        unordered_map<int,bool> upperLeftDiagnolCheck;
        unordered_map<int,bool> bottomLeftDiagnolCheck;

        bool isSafe(int row, int col, vector<vector<char>> &board, int n) {

            if(rowCheck[row] == true ){
                 return false;
            }

            if(upperLeftDiagnolCheck[n-1+col-row] == true){
                 return false;
            }

            if(bottomLeftDiagnolCheck[row+col] == true){
                 return false;
            }

            return true; 
        }


        void solve(vector<vector<char>> &board, int col, int n, int &totalSol) {
        //base case
        if(col >= n) {
            totalSol++;
            return ;
        }

        //1 case solve karna h , baaki recursion sambhal lega
        for(int row = 0; row <n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagnolCheck[n-1+col-row] = true;
                bottomLeftDiagnolCheck[row+col] = true;

                //recursion solution laega
                solve(board, col+1, n, totalSol);

                //backtracking
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagnolCheck[n-1+col-row] = false;
                bottomLeftDiagnolCheck[row+col] = false;
            }

        }
    }


    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        int col = 0, totalSol = 0;
        
        solve(board, col, n, totalSol);
        
        return totalSol;
    }
};