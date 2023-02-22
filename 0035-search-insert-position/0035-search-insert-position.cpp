class Solution {
public:
    // int indexUsingBinarySearch(vector<int> arr,int target){
    //     int start = 0;
    //     int end = arr.size()-1;
    //     int mid = start +(end-start)/2;
    //     int ans = -1;
    //     while(start<=end){
    //         if(arr[mid] == target){
    //             ans = mid;
    //         }
    //         else if(arr[mid]<target){
    //             start = mid+1;
    //         }
    //         else{
    //             end = mid-1;
    //         }
    //         mid = start +(end-start)/2;
    //     }
    //     return ans;
    // }
    
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start +(end-start)/2;
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
            mid = start +(end-start)/2;
        }
        return ans;
    }
};