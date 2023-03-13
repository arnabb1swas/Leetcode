class Solution {
public:
//     int binarySearchedindex(vector<int>& arr, int startingIndex,int target){
//     int start=startingIndex;
//         int end = arr.size()-1;
//         int mid = start+(end-start)/2;
        
//         while(start<=end){
//             if(arr[mid] == target){
//                 return mid;
//             }
//             else if(arr[mid]<target){
//                 start = mid+1;
//             }else{
//                 end = mid-1;
//             }
//             mid = start+(end-start)/2;
//         }
//         return -1;
//     }

    vector<int> twoSum(vector<int>& numbers, int target) {
//         for(int i=0;i<numbers.size();i++){
//             int newTarget = target-numbers[i];
//             int startingIndex = i+1;
//             int foundIndex = binarySearchedindex(numbers,startingIndex,newTarget);
            
//             if(foundIndex != -1){
//                 return {startingIndex,foundIndex+1};
//             }
//         }
//         return {};
        int start = 0 ; 
        int end = numbers.size() - 1 ; 

        while ((start <= end) && (numbers[start] + numbers[end] != target))
        {
            if (numbers[start] + numbers[end] < target)
            {
                start ++ ;  
            }
            else 
            {
                end -- ; 
            }
        }
        return {start + 1 ,end + 1} ; 
    
    }
};