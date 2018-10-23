/*
Description:Given a collection of distict numbers, return all possible permutations.

For examples,
[1,2,3] have the following permutations:
[
[1,2,3],
...
[3,2,1]
]

*/

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) return {{}};
    vector<vector<int>> result;
    int size = nums.size();
    int k;
    sort(nums.begin(), nums.end());
    result.push_back(nums);
    while (1) {
      k = -1;
      for (int i = size - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
          k = i;
          break;
        }
      }
      if (k == -1) return result;
      int l = 0;
      for (int i = size - 1; i >= 0; --i) {
        if (nums[i] > nums[k]) {
          l = i;
          break;
        }
      }
      swap(nums[l], nums[k]);
      reverse(nums.begin()+k+1, nums.end());
      result.push_back(nums);
    }
  }
}


// python way of coding
class Solution(object):
    # DFS
    def permute(self, nums):
        res = []
        self.dfs(nums, [], res)
        return res

    def dfs(self, nums, path, res):
        if not nums:
            res.append(path)
            # return # backtracking
        for i in xrange(len(nums)):
            self.dfs(nums[:i]+nums[i+1:], path+[nums[i]], res)
