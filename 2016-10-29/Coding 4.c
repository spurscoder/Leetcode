//问题描述：设计算法，找出只含因子2.3.5的第n个数		认为1也是丑数
//1,2,3,4,5,6,8,9,10,12...

/*
思路：丑数的乘积也是丑数
	从一个小数组逐渐乘积得到目标数组，同时，统计丑数个数，返回相应的丑数。
*/


class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int ugly[2000] = {0, 1, 2, 3};
        int T2 = 2;
        int T3 = 2;
        int T5 = 1;
        int min, temp;
        if (n <= 3)
            return ugly[n];
        for (int i = 4; i <= n; i ++) {
            temp = (ugly[T2] * 2 < ugly[T3] * 3) ? ugly[T2] * 2 : ugly[T3] * 3;
            min = (temp < ugly[T5] * 5) ? temp : ugly[T5] * 5;
            ugly[i] = min;
            if (ugly[T2] * 2 == min) T2++;
            if (ugly[T3] * 3 == min) T3++;
            if (ugly[T5] * 5 == min) T5++;
        }
        return min;
    }
};