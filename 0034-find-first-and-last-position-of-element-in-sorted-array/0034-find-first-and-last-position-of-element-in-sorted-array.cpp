class Solution {
public:
    int binarySearch(vector<int>& arr, int s, int e,int target, bool dir){
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                dir ? e = mid-1: s = mid+1;
            }
            else if (arr[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int e = nums.size()-1;
        return {binarySearch(nums, 0, e, target, true),binarySearch(nums, 0, e, target, false)};
    }
};