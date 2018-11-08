/*
问题描述：最长公共子序列
给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。

最长公共子序列的定义：
  最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，
  LCS不需要是连续的子串）。该问题是典型的计算机科学问题，是文件差异比较程序的基础，
  在生物信息学中也有所应用。

思路：
动态规划问题，，，，不同于最长公共子串

使用一个矩阵 通过构造矩阵各个元素从而得到相应的公共子序列
*/


class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.length() == 0 || B.length() == 0)
          return 0;
        int A_len = A.length();
        int B_len = B.length();

        //建立动态二维数组
        int **R = new int*[A_len+1];
        for (int i = 0; i <= B_len; i++)
          R[i] = new int[B_len];

        //初始化第一行和第一列
        for (int i = 0; i <= A_len; i++)
          R[i][0] = 0;
        for (int i = 0; i <= B_len; i++)
          R[0][i] = 0;

        //建立遍历数组
        for (int i = 1;i <= A_len; i++) {
          for (int j = 1;j <= B_len; j++) {
            if (A[i-1] == B[j-1])
              R[i][j] = R[i-1][j-1] + 1;
            else {
              if (R[i][j-1] >= R[i-1][j])
                R[i][j] = R[i][j-1];
              else
                R[i][j] = R[i-1][j];
            }
          }
        }

        //直接输出R[A_len][B_len] 即是 长度
        return R[A_len][B_len];

        //如果要输出相应的公共子序列，如下倒序输出        倒序打印的！！！
        for (int i = A_len,int j = B_len;i >= 1 && j >= 1 ;) {
          if (A[i-1] == B[i-1]) {
            cout << A[i-1] << " ";
            i--; j--;
          } else {
            if (R[i][j-1] > R[i-1][j])
              j--;
            else
              i--;
          }
        }
    }
};
