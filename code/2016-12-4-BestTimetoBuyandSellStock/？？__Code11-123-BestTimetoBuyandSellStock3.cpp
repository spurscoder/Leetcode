/*
Description:
Say you have an array for which the ith element is the price of a given stock on
day i. Design an algorithm to find the maximum profit. You may complete at most
two transactions.
Note:
You may not engage in multiple transactions at the same time(ie. you must sell
the stock before you buy again).

*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN, sale1 = 0;
    int buy2 = INT_MIN, sale2 = 0;
    for (int i = 0; i < prices.size(); i++) {
      buy1 = max(buy1, -prices[i]);
      sale1 = max(sale1, prices[i] + buy1);
      buy2 = max(buy2, sale1 - prices[i]);
      sale2 = max(sale2, prices[i] + buy2);
    }
    return sale2;
  }
};
