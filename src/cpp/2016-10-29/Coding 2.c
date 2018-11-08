// 问题描述：统计N!的结果中0的个数。

/*
思路1：N！= 2^x * 3^y * 5^z ...可以分解为质因数的多次乘积形式。
又知 x < z 一定成立。
于是可以从5开始，每隔5步，统计5的次数。
*/

/*
思路2：z = [N/5] + [N/5^2] + [N/5^3] + ...
仔细想想思路也是可以的。
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long num = 0;
        for (long long i = 5; i <= n; i *= 5)
            num += n/i;
        return num;
    }
};



/*
注意：数据类型要足够大
*/
