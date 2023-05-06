class Solution {
public:

    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagnolCheck;
    unordered_map<int,bool> bottomLeftDiagnolCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string> > &ans) {
        vector<string> temp;
        for(int i=0; i<n; i++) {
            string output = "";
            for(int j=0; j<n ;j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }


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


    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string> > &ans  ) {
    //base case
    if(col >= n) {
        storeSolution(board, n, ans);
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
            solve(board, col+1, n, ans);
            
            //backtracking
            board[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagnolCheck[n-1+col-row] = false;
            bottomLeftDiagnolCheck[row+col] = false;
        }

    }
}


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string> > ans;
        int col = 0;
        solve(board, col, n, ans);
        return ans;
    }
};