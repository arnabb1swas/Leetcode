class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while(left < right){
            int minHeight = min(height[left], height[right]);
            max_area = max(max_area, minHeight * (right - left));
            if (height[left] <= minHeight) {
                left++;
            }
            if (height[right] <= minHeight) {
                right--;
            }
        }
        
        return max_area;
    }
};