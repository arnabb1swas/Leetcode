class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
        int start = 0, ans = -1;
        int end = nums.size() - 1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
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
        }
        return ans;
    }
};