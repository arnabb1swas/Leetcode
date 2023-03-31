class Solution {
public:
    // Recurssion
//     int houseToRob(vector<int>& nums,int i){
//         if(i >= nums.size()) {
//             return 0;
//         }
        
//         int robAmnt1 = nums[i] + houseToRob(nums, i+2);
//         int robAmnt2 = 0 + houseToRob(nums, i+1);
        
//         return max(robAmnt1, robAmnt2);
//     }
    
//     int rob(vector<int>& nums) {
//         return houseToRob(nums, 0);
//     }
     int rob(vector<int>& nums){
        int newSum, exSum=0, sum=0;

        for (int num : nums)
        {
            newSum = max(exSum + num, sum);
            exSum = sum;
            sum = newSum;
        }

        return sum;
    }
};
