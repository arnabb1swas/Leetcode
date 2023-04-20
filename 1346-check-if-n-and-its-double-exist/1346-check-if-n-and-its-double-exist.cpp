class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return -1;
    }
    
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++){
            int val = binarySearch(arr, arr[i]*2); 
            if(val != -1 && val != i){
                return true;
            }
        }
        
        return false;
    }
};