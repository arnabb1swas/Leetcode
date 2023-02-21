class Solution {
  public: int maxProfit(vector < int > & prices) {
      int lssf = INT_MAX; //least stock so far
      int op = 0; //overall profit
      int pist = 0; //profit if sold today

      for (int i = 0; i < prices.size(); i++) {
        //Updating least stock till now
        if (lssf > prices[i]) {
          lssf = prices[i];
        }

        //Amount of profit if sold today
        pist = prices[i] - lssf;

        //maximum overall profit till now
        op = max(op, pist);
      }

      return op;
  }
};