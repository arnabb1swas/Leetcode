class Solution {
public:
    vector<int> twoPointer(vector<int>& arr, int k, int x){
        int start = 0, end = arr.size() - 1;
        while(end-start>=k){
           if(x-arr[start] > arr[end]-x){
               start++;
           } else {
               end--;
           }
        }
        return vector<int>(arr.begin()+start, arr.begin()+end+1);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointer(arr,k,x);
    }
};