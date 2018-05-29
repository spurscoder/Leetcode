/*
the visualization help me to understand hope it can help you too.

1···················1

add two 1 at beginning and end of nums, each · represent each number in nums.

len is the subinterval length, it grows from 1 to full length of orignal nums string.

the following illustrations demonstrate how the subinterval shift from left to right. (len = 7 in the illustration)

for each len, when shifted to rightmost, increase len and do the shift again. this way we can evaluate all possible subintervals.

for each subinterval, in the innermost for loop, find which balloon to burst LAST that will give us the most coins for that subinterval. <- IMPORTANT TO UNDERSTAND THIS

dp[left][right] is the maximum coins we can get from left to right. note when left > right, it is 0

   1···················1    (len = 7)
    |     |
  left  right
  
   1···················1
           |     |
         left  right
          
   1···················1
                |     |
              left  right
for the example [3, 1, 5, 8], the dp matrix is updated like this

0    0    0    0    0    0
0    3    0    0    0    0
0    0    15   0    0    0
0    0    0    40   0    0
0    0    0    0    40   0
0    0    0    0    0    0
then

0    0    0    0    0    0
0    3    30   0    0    0
0    0    15   135  0    0
0    0    0    40   48   0
0    0    0    0    40   0
0    0    0    0    0    0
at last

0    0    0    0    0    0
0    3    30   159  167  0
0    0    15   135  159  0
0    0    0    40   48   0
0    0    0    0    40   0
0    0    0    0    0    0
the code is like most others.
这道题的参加2D dp的思路解决，不容易理解，如下图所示，首先，计算对角线上的元素值
（出去两头），然后依次向上三角区域的方向推进计算，len控制的就是计算的长度。
下面的dp矩阵，dp[i][j]表示燃烧掉i到j之间气球能产生的最大值。
计算dp[i][j]的思路是依次假定i到j中一个气球是最后燃烧的，比如说k（k在i到j之间）
是最后燃烧的，那么在这个假定成立的前提下，最大收益是
nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]

比如计算dp[2][5] 时，要用到
dp[2][3] dp[2]4] dp[2][2] dp[3][5] dp[4][5]
上面的含义推广开来就是，左侧和下测的值需要先计算出来，这也是为什么这样控制计算顺序的原因
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len ) {
            for (int left = 1; left <= n-len+1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                    dp[left][right] = max(dp[left][right], 
                        nums[left-1]*nums[k]*nums[right+1]+dp[left][k-1]+dp[k+1][right]);
            }
        }
        return dp[1][n];
    }
};


int main() {
    Solution sol = Solution();

    return 0;
}