class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        
        if(nums[1]<nums[0]){
            return 0;
        }
        
        if(nums[nums.size()-2]<nums[nums.size()-1]){
            return nums.size()-1;
        }
        
        int i=1,j=nums.size()-2;
        int mid=(i+j+1)/2;
        int ans=0;
        
        while(i<=j){
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid-1] ){
                j=mid-1;
            }
            else if(nums[mid]<nums[mid+1]){
                i=mid+1;
            }
            mid=(i+j+1)/2;
        }
        
        return ans;
    }
};