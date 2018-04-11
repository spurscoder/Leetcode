/*
Description: combination Sum ||
Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.

Notice
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order.
(ie, a1 ≤ a2 ≤ … ≤ ak).

The solution set must not contain duplicate combinations.
*/


class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > results;
        vector<int> vect;
        int n = num.size();
        if (n == 0) return results;
        sort(num.begin(), num.end());
        backtracing(results, vect, num, 0, n, target);
        return results;
    }
    map<vector<int>, bool> check;
    void backtracing(vector<vector<int> > &results, vector<int> &vect, vector<int> &num, int cur, int n, int left)
    {
      if (0 == left)
      {
        if (0 == check.count(vect))
        {
          results.push_back(vect);
          check[vect] = true;
        }
        return;
      }
      for (int i = cur; i < n; i++)
      {
        if (num[i] <= left)
        {
          vect.push_back(num[i]);
          backtracing(results, vect, num, i+1, n, left - num[i]);
          vect.pop_back();
        }
      }
      return;
    }
};
