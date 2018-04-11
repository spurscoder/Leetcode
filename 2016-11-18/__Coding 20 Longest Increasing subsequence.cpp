/*
问题描述：最长上升子序列
给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。
最长上升子序列的定义：
最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的
由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。

挑战 ：
要求时间复杂度为O(n^2) 或者 O(nlogn)

标签 ：
二分法 LintCode 版权所有 动态规划


思路：
如何把这个问题分解成子问题呢？经过分析，发现 “求以ak（k=1, 2, 3…N）为终点的最长上升子序列的
长度”是个好的子问题――这里把一个上升子序列中最右边的那个数，称为该子序列的“终点”。虽然这个
子问题和原问题形式上并不完全一样，但是只要这N个子问题都解决了，那么这N个子问题的解中，最大的
那个就是整个问题的解。
由上所述的子问题只和一个变量相关，就是数字的位置。因此序列中数的位置k 就是“状态”，
而状态 k 对应的“值”，就是以ak做为“终点”的最长上升子序列的长度。这个问题的状态一共有N个。
状态定义出来后，转移方程就不难想了。假定MaxLen (k)表示以ak做为“终点”的最长上升子序列的长度，
那么：
MaxLen (1) = 1
MaxLen (k) = Max { MaxLen (i)：1<i < k 且 ai < ak且 k≠1 } + 1
这个状态转移方程的意思就是，MaxLen(k)的值，就是在ak左边，“终点”数值小于ak，且长度最大的那个
上升子序列的长度再加1。因为ak左边任何“终点”小于ak的子序列，加上ak后就能形成一个更长的上升子序列。
实际实现的时候，可以不必编写递归函数，因为从 MaxLen(1)就能推算出MaxLen(2)，有了MaxLen(1)和
MaxLen(2)就能推算出MaxLen(3)……
*/


class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        // write your code here
      int size = nums.size();
      int *state = new int[size];
      int max, maxlen = 0;
      for (int i = 0 ; i < size; i++)
      {
        state[i] = 1;
      }
      for (int i = 1; i < size; i++)
      {
        max = 0;
        for (int j = 0; j <= i; j++)
        {
          if (nums[i] > nums[j] && state[j] > max)
            max = state[j];
        }
        state[i] = max + 1;
        if (max + 1 > maxlen)
          maxlen = max + 1;
      }
      return maxlen;
    }
};
