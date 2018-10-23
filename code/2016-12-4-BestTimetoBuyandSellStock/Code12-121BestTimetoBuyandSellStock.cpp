/*
Description:
Say you have an array for which the ith element is the price of a given stock on
day i. If you were onlu permitted to complete at most one transaction (ie. buy one and
sell one share of the stock), design an algotithm to find the maximum profit.

Tags: Array, Dynamic Programming

*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxpro = 0;
    int minpri = INT_MAX;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
      minpri = minpri > prices[i] ? prices[i] : minpri;
      maxpro = maxpro > prices[i] - minpri ? maxpro : prices[i] - minpri;
    }
    return maxpro;
  }
};
