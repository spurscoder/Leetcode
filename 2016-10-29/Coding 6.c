/*
问题描述：完美平方
给一个正整数n,找到若干个完全平方数(比如1,4,9,...)
使得他们的和等于n,你需要让平方数的个数最少。
*/

/**
思路：动态规划。这是一道典型的动态规划问题

1.首先如何定义问题？真个问题就是，f(i)=对于任意一个正整数i,求i由多少个整数平方和组成。
2.如何得到最终问题f(n)？方法就是从1开始计算，f(1),f(2),直到f(n)
3.每个f(i)如何计算？每个f(i)只和前面的f值有关。

思路二：用到“四平方和定理”	---...---
		....

*/



class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        int *num = new int[n + 1];
        // initialize
        for (int i = 0; i <= n; i++)
        	num[i] = i;
        for (int i = 2; i <= n; i++) {
        	for (int j = 1; j*j <= i; j++) {
        		num[i] = min(num[i], num[i-j*j] + 1);
         	}
        }
        return num[n];
    }
};



//c++ 中的取最小值函数 min()