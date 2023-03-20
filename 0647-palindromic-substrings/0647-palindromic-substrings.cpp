class Solution {
public:
    int expandAroundIndex(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++; i--; j++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        for(int i=0; i<n; i++){
            count += expandAroundIndex(s,i,i); // odd check
            count += expandAroundIndex(s,i,i+1); //even check
        }
        return count;
    }
};