/*
问题描述：带重复元素的排列
给出一个具有重复数字的列表，找出列表所有不同的排列。

样例：
给出列表 [1,2,2]，不同的排列有：
  [1,2,2],
  [2,1,2],
  [2,2,1]

挑战：使用递归和非递归分别完成此问题

标签：领英 递归 深度优先搜索

思路：


permutations:序列 排列
*/

/************************************************递归方法
从前往后，不断改变顺序得出相应的数组元素
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int> > permutations;
        permutate(nums, 0, permutations);
        return permutations;
      }

      void permutate(vector<int> nums, int start, vector<vector<int>> &permutations)
      {
        if (start == nums.size())
        {
          permutations.push_back(nums);
          return;
        }
        for (int i = start; i < (int)nums.size(); i++)
        {
          if (i == start || nums[i] != nums[start])
          {
            swap(nums[start], nums[i]);
            permutate(nums, start + 1, permutations);
          }
        }
      }
};

/**************************************************************非递归方法
先排序，之后从后向前不断的改变顺序，得出排列

***/
class Solution {
public:

     bool nextPermutation(vector<int> &nums) {

        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]<nums[j]){
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int> > permuteUnique(vector<int> &nums) {

        vector<vector<int> > ret;
        sort(nums.begin(),nums.end());

        do{
            ret.push_back(nums);
        }while(nextPermutation(nums));

        return ret;
    }
};
