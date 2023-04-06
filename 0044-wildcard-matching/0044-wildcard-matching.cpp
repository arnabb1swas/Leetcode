class Solution {
public:
    // dsa solution
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
    
    bool isMatch(string& s, string& p) {
        if(p.size()==0) return s.size() == 0;
        
        int x = s.size(), y = p.size();
        vector<vector<int>> t(x+1, vector<int>(y+1,0));
        
        t[0][0] = 1;
        
        for(int i=1; i<=p.size(); i++){
            if(p[i-1] == '*') t[0][i] = 1;
            else break;
        }
        
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(p[j-1] == '*')  t[i][j] = t[i-1][j] || t[i][j-1];
                else if(p[j-1] == '?' || p[j-1] == s[i-1]) {
                    t[i][j] = t[i-1][j-1];
                }
            }
        }
        return t[x][y];
    }
};