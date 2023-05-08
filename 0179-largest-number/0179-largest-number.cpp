class Solution {
public:
    static bool comparator(string a, string b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i:nums){
            ans.push_back(to_string(i));
        }
        
        sort(ans.begin(), ans.end(), comparator);

        string result;
        for(int i=0; i<ans.size(); i++){
            result+=ans[i];
        }

        return result[0]=='0'? "0" : result;
    }
};