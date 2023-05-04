//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafeToMove(int newx, int newy, int row, int col, vector<vector<int>> &maze, vector<vector<bool>> &visited){
        if (
            ((newx >= 0 && newx < row) && (newy >= 0 && newy < col)) && // check for valid index
            maze[newx][newy] == 1 &&                                    // check for valid cell
            visited[newx][newy] == false)                               // check for visited cell
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
    int dy[4] = {0, 0, -1, 1}; // U, D, L, R
    char direction[4] = {'U', 'D', 'L', 'R'};
    
    void solveMaze(vector<vector<int>> &maze, int row, int col, int srcx, int srcy, vector<vector<bool>> &visited, string output, vector<string> &path){
        if (srcx == row - 1 && srcy == col - 1){
            path.push_back(output);
            return;
        }
    
        for (int i = 0; i < 4; i++){
            int newx = srcx + dx[i];
            int newy = srcy + dy[i];
            char dir = direction[i];
    
            if (isSafeToMove(newx, newy, row, col, maze, visited)){
                visited[newx][newy] = true;
                solveMaze(maze, row, col, newx, newy, visited, output + dir, path);
                // backtracking
                visited[newx][newy] = false;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> path;
        string output = "";
        
        if(m[0][0] == 0){
            return path;
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        solveMaze(m, n, n, 0, 0, visited, output, path);
        
        return path;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends