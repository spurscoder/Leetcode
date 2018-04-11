/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the
stock before you buy again).
*/

class Solution {
public:
   int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      if (k>=n/2) {
          int sum = 0;
          for(int i=1; i<n; i++){
              if(prices[i] > prices[i-1]){
                  sum += prices[i] - prices[i-1];
              }
          }
          return sum;
      }
      vector<int> buy(k+1, INT_MIN), sale(k+1, 0);
      for(int i=0; i<n; i++){
          for(int j=1; j<=k; j++){
              buy[j] = max(buy[j], sale[j-1]-prices[i]);
              sale[j] = max(sale[j], buy[j] + prices[i]);
          }
      }
      return sale[k];
  }
};
