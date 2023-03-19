class Solution {
public:
    bool checkPalindrom(string s,int i,int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i<=j){ 
            if(s[i]!=s[j]){
                return checkPalindrom(s,i+1,j) || checkPalindrom(s,i,j-1);
            }else{
                i++; j--;
            }
        }
        return true;
    }
};