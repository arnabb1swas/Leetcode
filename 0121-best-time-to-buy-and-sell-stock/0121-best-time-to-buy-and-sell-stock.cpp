class Solution {
  public: 
//     int maxProfit(vector<int>& prices) {
//       // => [7,1,5,3,6,4]
//       // price   lssf    pist    op
//       //----------------------------
//       // 7       7       0       0
//       // 1       1       0       0
//       // 5       1       4       4
//       // 3       1       2       4
//       // 6       1       5       5
//       // 4       1       3       5
        
//       int lssf = INT_MAX; //least stock so far
//       int op = 0; //overall profit
//       int pist = 0; //profit if sold today

//       for (int i = 0; i < prices.size(); i++) {
//         //Updating least stock till now
//         if (lssf > prices[i]) {
//           lssf = prices[i];
//         }

//         //Amount of profit if sold today
//         pist = prices[i] - lssf;

//         //maximum overall profit till now
//         op = max(op, pist);
//       }

//       return op;
//   }
    
    void maxProfitFinder(vector<int>&prices, int i, int&minPrice, int&maxProfit){
        if(i==prices.size()) return;
        
        if(prices[i] < minPrice) minPrice = prices[i];
        int todaysProfit = prices[i] - minPrice;
        if(todaysProfit > maxProfit) maxProfit = todaysProfit;
        maxProfitFinder(prices, ++i, minPrice, maxProfit);
    }
    
    // using recurssion
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = INT_MIN;
        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};
