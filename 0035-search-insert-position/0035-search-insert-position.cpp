class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end-start)/2;
        int ans = -1;
        
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            }
            else if(mid<nums.size() && nums[mid]<target){
                ans = mid+1;
                start = mid+1;
            }
            else if(mid>=0 && nums[mid]>target){
                ans = mid;
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
};