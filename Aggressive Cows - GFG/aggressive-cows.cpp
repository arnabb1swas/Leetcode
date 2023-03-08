//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossibleSolnAC(vector<int> &stalls, int n, int k, int sol){
        // can we place k cows, with atleast sol distance btw cows
        int cowCounter = 1;
        int pos = stalls[0];
        for(int i = 1; i < n; i++){
            if(stalls[i]-pos >= sol){
                cowCounter++;
                pos = stalls[i]; // one more cow has been placed
            }
            if(cowCounter == k) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 0, end = stalls[n-1] - stalls[0];
        int ans = -1;
        
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(isPossibleSolnAC(stalls, n, k, mid)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends