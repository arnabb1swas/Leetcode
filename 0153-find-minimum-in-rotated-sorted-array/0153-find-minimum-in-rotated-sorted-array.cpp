class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        if (!end) return nums[0]; // only one element

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            // got a part that is not rotated
            if (nums[start] < nums[end]) return nums[start]; 

            // mid is larger than right - min is in right side
            else if (nums[mid] > nums[end]) start = mid + 1;

            // mid is smaller than right - min is in left side (including mid)
            else end = mid;
        }
        return nums[start];
    }
};