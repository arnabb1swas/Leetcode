class Solution {
public:
//    // dsa solution
//     bool isMatchHelper(string &s, int si, string &p, int pi){
//         // base case 1:
//         if (si == s.size() && pi == p.size()){
//             return true;
//         }

//         // base case 2:
//         if (si == s.size() && pi < p.size()){
//             while (pi < p.size()){
//                 if (p[pi] != '*') {
//                     return false;
//                 }
//                 pi++;
//             }
//             return true;
//         }

//         // single char matching
//         if (s[si] == p[pi] || p[pi] == '?'){
//            return isMatchHelper(s, si+1, p, pi+1);
//         }

//         if (p[pi] == '*'){
//             //  treat '*' as empty char '' or null.
//             bool caseA = isMatchHelper(s, si, p, ++pi);

//             //  '*' consumes a single char from string s.
//             bool caseB = isMatchHelper(s, ++si, p, pi);

//             return caseA || caseB;
//         }

//         return false;
//     }

//     // Wildcard Matching
//     bool isMatch(string s, string p){
//         int si = 0, pi = 0;
//         return isMatchHelper(s, si, p, pi); // intializing pointer to 0 for string s & p   
//     }
    
    bool solve(string &s,string &p,int i,int j,int &m,int &n,vector<vector<int>> &v){
        if(i==m&&j==n)return true;
        if(i == m){
            for(int k = j; k < n; k++){
                if(p[k] != '*')return false;
            }
            return true;
        }
        if(j == n && i != m)return false;
        
        if(v[i][j] != -1)return v[i][j];
        bool ans = false;
        if(p[j]==s[i]){
            if(solve(s,p,i+1,j+1,m,n,v))
            ans = true;
        }
        if(p[j]== '?'){
            if(solve(s,p,i+1,j+1,m,n,v))
            ans= true;
        }
        else if(p[j] == '*'){
            if(solve(s,p,i+1,j+1,m,n,v)){
                ans = true;
            }if(solve(s,p,i+1,j,m,n,v)){
                ans = true;
            }if(solve(s,p,i,j+1,m,n,v)){
                ans = true;
            }
        }
        v[i][j] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> v(m,vector<int>(n,-1));
        return solve(s,p,0,0,m,n,v);
    }
};