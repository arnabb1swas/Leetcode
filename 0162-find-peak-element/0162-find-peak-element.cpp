class Solution {
public:
        int findPeakElement(vector<int>& nums) {
        int startingIndex = 0;
        int lastIndex = nums.size()-1;
        int midIndex = startingIndex + (lastIndex-startingIndex)/2;

        while(startingIndex<lastIndex){
            if(nums[midIndex]<nums[midIndex+1]){
                startingIndex = midIndex +1;
            }else{
                lastIndex = midIndex;
            }
            midIndex = startingIndex + (lastIndex-startingIndex)/2;
        }
            
        return startingIndex;
    }
};