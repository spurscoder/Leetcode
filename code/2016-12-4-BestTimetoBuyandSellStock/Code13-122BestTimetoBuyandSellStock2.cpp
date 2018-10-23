/*
Description:
Say you have an array for which the ith element is the  price of a given stock on
day i, Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie. buy one and sell one share of the stock multiple
times). However, you may not engage in multiple transactions at the same time
(ie. you must sell the stock before you buy again).

Tags : Array, Greedy.

Explanation:
Second, suppose the first sequence is "a <= b <= c <= d", the profit is
"d - a = (b - a) + (c - b) + (d - c)" without a doubt. And suppose another one
is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as
"(b - a) + (d - b')". So you just target at monotone sequences.
*/

class Solution {
public:
  int maxProfit (vector<int>& prices) {
    int maxpro = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      maxpro += max(prices[i+1] - prices[i], 0);
    }
    return maxpro;
  }
};


// Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(len(prices) - 1))
        
