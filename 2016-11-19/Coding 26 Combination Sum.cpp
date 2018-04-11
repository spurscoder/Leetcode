/*
Description : combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique
combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

Notice:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Backtracking array



递归形式
使用了map和vector
*/



class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > results;
        vector<int> vect;
        int n = candidates.size();
        if (n == 0)
          return results;
        sort(candidates.begin(),candidates.end());
        backtracing(results, vect, candidates, 0, n, target);
        return results;
     }
     map<vector<int>, bool> check;  // 检查是否已经添加到了results中
     void backtracing(vector<vector<int> > &results, vector<int> &vect, vector<int> &candidates, int cur, int n, int left)
     {
       if (0 == left)
       {
         if (0 == check.count(vect))    //  添加到results中
         {
           results.push_back(vect);
           check[vect] = true;
         }
         return;
       }
       for (int i = cur; i < n; i++)
       {
         if (candidates[i] <= left)
         {
           vect.push_back(candidates[i]);
           backtracing(results, vect, candidates, i, n, left - candidates[i]);
           vect.pop_back();
         }
       }
       return;
     }
};
