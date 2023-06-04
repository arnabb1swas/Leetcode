class Solution {
public:
//     void solve(int target, vector<int>& candidates, int idx, vector<vector<int>>& v, vector<int> &ans){
//         if(idx == candidates.size()){
//             if(target == 0){
//                 v.push_back(ans);
//             }
            
//             return; 
//         }
//         if(target>=candidates[idx]){
//             ans.push_back(candidates[idx]);
//             solve(target-candidates[idx],candidates,idx,v,ans);
//             ans.pop_back();
//         }
        
//         solve(target,candidates,idx+1,v,ans);
//     }
    
    void find_subs(int i,vector<int> &candidates,vector<vector<int>> &ans, int target, vector<int> &list)
    {
      if(i>=candidates.size())
      {   
          if(target==0)
             ans.push_back(list);
          return;
      }
      if(candidates[i]<=target)
      {
      list.push_back(candidates[i]);
      find_subs(i,candidates,ans,target-candidates[i],list);
      list.pop_back();
      }
      find_subs(i+1,candidates,ans,target,list);
    }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> list;
       find_subs(0,candidates,ans,target,list);
       return ans; 
    }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector <int> ans;
//         vector <vector<int>> v;
//         solve(target,candidates,0,v,ans);
//         return v;
//     }
};