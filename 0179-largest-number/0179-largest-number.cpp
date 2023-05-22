class Solution {
public:
    static bool check(string &s1, string &s2){
        return (s1 +s2)>=(s2 + s1);
    }
    
//     string largestNumber(vector<int>& nums) {
//         vector<string> ans;
//         for(int i:nums){
//             ans.push_back(to_string(i));
//         }
        
//         sort(ans.begin(), ans.end(), comparator);

//         string result;
//         for(int i=0; i<ans.size(); i++){
//             result+=ans[i];
//         }

//         return result[0]=='0'? "0" : result;
//     }

    string largestNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                x++;
            }
        }
        if(x == nums.size()) return "0";

        vector<string> s(nums.size(), "");

        for(int i=0; i<nums.size();i++){
            s[i]= to_string(nums[i]);
        }

        sort(s.begin(), s.end(), check);
        string ans = "";

        for(int i=0; i<s.size(); i++){
            ans += (s[i]);
        }

        return ans;
    }
};