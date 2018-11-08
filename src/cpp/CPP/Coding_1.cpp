//问题描述： 不使用+的数学运算符 进行Ａ＋Ｂ操作 

//思路： A^B得本位和  A&B得进位 保证进位为0即可.

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while (b != 0) {
            int x = a^b;
            int y = (a&b) << 1;
            a = x;
            b = y;
        }
        return a;
    }
};
