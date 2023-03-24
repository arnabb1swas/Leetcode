class Solution {
public:
    // // by sliding window method
    // int strStr(string haystack, string needle){
    // int n = haystack.length(), m = needle.length();
    // for (int i = 0; i <= n - m; i++){
    //     for (int j = 0; j < m; j++){
    //         if (needle[j] != haystack[i + j]){
    //             break;
    //         }
    //         if (j == m - 1){
    //             return i;
    //         }
    //     }
    // }
    // return -1;
    // }
    
    int strStr(string haystack, string needle){
        return haystack.find(needle);
    }
};