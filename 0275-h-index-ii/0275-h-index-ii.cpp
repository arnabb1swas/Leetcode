class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0, high =citations.size()-1;
        int ans=0;
        int n = citations.size();
        while(low<=high){
            int mid = low + (high - low)/2;
            if(citations[mid]==0){
                low=mid+1;
            }
            else{
                if(citations[mid] <= n - mid){
                    ans=max(ans,citations[mid]);
                    low = mid + 1;
                }
                else{
                    ans=max(ans, n -mid);
                    high = mid - 1;
                }
            }
        }
        
        return ans;
    }
};