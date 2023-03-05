class Solution {
public:
    bool canBeLoaded(vector<int>& weights, int N, int M, int sol){
        int packageWeight = 0;
        int dayCount = 1;
        for(int i=0; i<N; i++){
            if(weights[i]>sol) {
                return false;
            }
            if(packageWeight + weights[i] > sol){
                dayCount++;
                packageWeight = weights[i];
                if(dayCount>M){
                    return false;
                }
            }
            else{
                packageWeight += weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        if (days>N) return -1;
        
        int start = 0;
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(canBeLoaded(weights, N, days, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};