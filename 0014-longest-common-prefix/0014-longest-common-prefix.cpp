class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sorting the vector of strings
        // strs = ["flower","flow","flight"]
        sort(strs.begin(), strs.end());
        // strs = ["flight","flow","flower"]
        int a = strs.size();
        string n = strs[0], m = strs[a - 1], ans = "";
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == m[i]){
                ans += n[i];
            }else{
                break;           
            }
        }
        return ans;
    }
};