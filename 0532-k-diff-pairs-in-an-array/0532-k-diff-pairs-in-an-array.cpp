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
  //     // Two Pointer
  //     int findPairs(vector<int>& nums, int k) {

  //     // sort the array so that we can use 2 pointers method
  //     sort(nums.begin(), nums.end());
  //     int i = 0, j = 1;
  //     set<pair<int, int>> pairCount;

  //     while (j < nums.size())
  //     {
  //         int diff = nums[j] - nums[i];
  //         if (diff == k){
  //             pairCount.insert({nums[i], nums[j]});
  //             i++, j++;
  //         }
  //         else if (diff > k){ // if diff is getting bigger reduce it
  //             i++;
  //         }
  //         else{ // if diff is getting smaller increase it
  //             j++;
  //         }
  // // edge case 0
  // // any number will be a pair, u can '-' the number from itself and you have a pair
  //         if (i == j){ 
  //             j++;
  //         }
  //     }

  //     return pairCount.size();
  //     }

  // Binary Search
  int findPairs(vector < int > & nums, int k) {
    // sort the array so that we can use 2 pointers method
    sort(nums.begin(), nums.end());
    set < pair < int, int > > pairCount; //  using sets to get unique pairs
    for (int i = 0; i < nums.size(); i++) {
      if (binarySearch(nums, i + 1, nums[i] + k)!= -1) {
        pairCount.insert({ nums[i], nums[i] + k });
      }
    }

    return pairCount.size();
  }
};