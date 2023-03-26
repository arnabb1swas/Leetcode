class Solution {
public:
    bool isSafeToInsert(vector<vector<char>> &board, int row, int col, char value){
        int n = board[0].size();

        for (int i = 0; i < n; i++){
            // check row
            if (board[row][i] == value){
                return false;
            }

            // check col
            if (board[i][col] == value){
                return false;
            }

            // check 3x3 box
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value){
                return false;
            }
        }

        return true;
    }

    bool solveBoard(vector<vector<char>> &board){
        int n = board[0].size();

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                /// check for empty cell
                if (board[i][j] == '.'){
                    // try to fill with values ranging from 1-9
                    for (char val = '1'; val <= '9'; val++){
                        // check for safety
                        if (isSafeToInsert(board, i, j, val)){
                            board[i][j] = val;

                            // recurssion will handle all the other solutions
                            bool nextSolution = solveBoard(board);
                            if (nextSolution){
                                return true;
                            }
                            else{
                                // backtrack the board's sol
                                board[i][j] = '.';
                            }
                        }
                    }
                    // if 1 se 9 tak koi bhi value se solution nai nikla matlab
                    // piche kahi galti hai to return false
                    // taki piche change karke age ke values check kar sake
                    return false;
                }
            }
        }
        // cell traverse ho chuka hai cuz sare element filled hai
        // matlab soltion mil chuka hai, so return true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveBoard(board);
    }
};