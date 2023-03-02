class Solution {
  public:

    int binarySearch(vector < int > arr, int start, int target) {
      int end = arr.size() - 1;
        
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
          return mid;
        else if (arr[mid] > target)
          end = mid - 1;
        else
          start = mid + 1;
      }
      return -1;
    }

  // Binary Search
  int findPairs(vector < int > & nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int,int>> pairCount;
      
    for (int i = 0; i < nums.size(); i++) {
      if (binarySearch(nums, i + 1, nums[i] + k)!= -1) {
        pairCount.insert({ nums[i], nums[i] + k });
      }
    }

    return pairCount.size();
  }
};