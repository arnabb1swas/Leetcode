class Solution {
  public:
  int findPairs(vector < int > & nums, int k) {
        // sort the array so that we can use 2 pointers method
    sort(nums.begin(), nums.end());
    int i = 0, j = 1;
    set<pair<int, int>> pairCount;

    while (j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            pairCount.insert({nums[i], nums[j]});
            i++, j++;
        }
        else if (diff > k)
        {
            i++; // if diff is getting bigger reduce it
        }
        else
        {
            j++; // if diff is getting smaller increase it
        }
        // edge case 0
        // any number will be a pair, u can '-' the number from itself and you have a pair
        if (i == j)
        {
            j++;
        }
    }
    return pairCount.size();
  }
};