/**
Description: Combinations
Given two integers n and k, return all possible Combinations of k numbers out of
1...n

For example,
if n = 4 and k = 2, a solution is:
[[2,4],[2,3],[3,4],[1,2],[1,3],[1,4]]

Tags:
Backtracking, Array
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > results;
        vector<int> temp;
        if (k == 0 || n == 0)
          return results;
        backTracking(results, temp, 1, n, k);
        return results;
    }
    void backTracking(vector<vector<int> > &results, vector<int> &temp, int cur,
                        int n, int left)
    {
      if (left == 0)
      {
        results.push_back(temp);
        return;
      }

      for (int i = cur; i <= n; i++)
      {
        temp.push_back(i);
        backTracking(results, temp, i+1, n, left-1);
        temp.pop_back();
      }
    }
};
