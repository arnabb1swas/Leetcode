class Solution {
public:
//     int negativeValuesPerRow(vector<int>& arr){
//         int start = 0, end = arr.size() - 1;
//         while (start <= end) {
//             int mid = start + (end - start) / 2; // 1, 2, 
//             if (arr[mid] >= 0) {
//                 start = mid + 1;
//             } else {
//                 end = mid - 1;
//             }
//         }
//         return arr.size() - end - 1;
//     }
    
    int countNegatives(vector<vector<int>>& grid) {
        // int count = 0;
        // for(int i=0; i< grid.size(); i++){
        //     count += negativeValuesPerRow(grid[i]);
        // }
        // return count;
        int i=0;
       int j=grid[0].size()-1;
       int count=0;
       while(i<grid.size()&&j>=0)
       {
           if(grid[i][j]<0)
           {
               count+=(grid.size()-i);
               j--;
           }
           else if(grid[i][j]>=0)
           {
               i++;
           }


       }
       return count;
    }
};