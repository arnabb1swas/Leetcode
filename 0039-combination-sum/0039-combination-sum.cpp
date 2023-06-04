class Solution {
public:
    void solve(int target, vector<int>& candidates, int idx, vector<vector<int>>& v, vector<int> &ans){
        if(idx == candidates.size()){
            if(target == 0){
                v.push_back(ans);
            }
            return; 
        }
        if(target>=candidates[idx]){
            ans.push_back(candidates[idx]);
            solve(target-candidates[idx],candidates,idx,v,ans);
            ans.pop_back();
        }
        
        solve(target,candidates,idx+1,v,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> ans;
        vector <vector<int>> v;
        solve(target,candidates,0,v,ans);
        return v;
    }
};