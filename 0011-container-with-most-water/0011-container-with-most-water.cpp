class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int i=0,j=height.size()-1;
        int ans=0;
        while(j>=i)
        {
            ans=max(ans,min(height[j],height[i])*(j-i));
            if (height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};