class Solution {
public:
    bool judgeSquareSumTwoPointers(int c){
        long int i = 0, j = (int)sqrt(c);
        if(c<0){
            return false;
        }
        while(i<=j){
            long int sum = i*i + j*j;
            if(sum == c){
                return true;
            }
            else if(sum<c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
    
//     bool judgeSquareSumBinarySearch(int c){
        
//     }
    
    // int binarySearch(vector<int>& nums, int target) {
    //     int start = 0, end = nums.size() - 1;
    //     while (start <= end){
    //         int mid = start + (end - start) / 2;
    //         if (nums[mid] == target)
    //             return mid;
    //         else if (nums[mid] > target)
    //             end = mid - 1;
    //         else
    //             start = mid + 1;
    //     }
    //     return -1;
    // }
    
    bool judgeSquareSum(int c) {
        return judgeSquareSumTwoPointers(c);
        // return judgeSquareSumBinarySearch(c);
    }
};