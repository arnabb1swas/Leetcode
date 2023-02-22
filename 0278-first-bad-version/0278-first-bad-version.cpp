// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n, ans = 0;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            bool isBad = isBadVersion(mid);
            if(isBad){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};