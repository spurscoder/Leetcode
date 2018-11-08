//问题描述：统计数字，计算数字k在0到n中出现的次数，k可能是0-9中的任意值

/*
思路及分析： 对于abcd四位数字及k
	1	k<d			k=d			k>d
		abc*1+1		abc*1+0+1	abc*1
	2	k<c			k=c			k>c
		ab*10+10	ab*10+d+1 	ab*10
	3 	k<b			k=b			k>b
		a*100+100	a*100+cd+1 	a*100
	4	k<a 		k=a 		k>a
		0*1000+1000	0*1000+bcd+1	0
总结规律：
	k<a时，left * level + level;
	k=a时，left * level + right + 1;
	k>a时，left * level;
对于k=0时候，特殊处理。
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int left = 0;
        int right = 0;
        int current = 0;
        int level = 1;
        int count = 0;
        while (n / level != 0) {
            right = n % level;
            left = n / (level * 10);
            current = (n / level) % 10;
            if (current > k)
                count += left * level + level;
            else
            if (current == k)
                count += left * level + right + 1;
            else
                count += left * level;
            level *= 10;
        }
        if (k == 0) {
            if (n == 0)
                count = 1;
            else
                count -= (level / 10);
        }
        return count;
    }
};