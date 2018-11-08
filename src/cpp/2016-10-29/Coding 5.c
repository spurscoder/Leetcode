/*
问题描述：
超级丑数：求第n个超级丑数
		超级丑数是正整数且所有的质数因子都在所给定的一个大小为k的质数集合内
		例如：集合[2,7,13,19] 相应的超级质数集合为[1,2,4,7,8,13,14,16,19,26,28,32,...]
*/

/*
思路：由丑数的解题思路得出，可以从一个小集合逐步乘积得到一个目标集合，即超级丑数集合。
	index[] 记住乘积的位置
	temp[]  记住暂时结果
	result[] 结果数组.
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        int m = primes.size();
        vector<int> index(m, 0);
        vector<int> temp(m, 0);
        vector<int> result(n, 1);
        for (int i = 1; i < n; i++) {
        	for (int j = 0; j < m; j++)
        		temp[j] = result[index[j]] * primes[j];
        	int min = *min_element(temp.begin(), temp.end());
        	for (int j = 0; j < m; j++)
        		if (min == temp[j])
        			index[j]++;
        	result[i] = min;
        }
        return result[n - 1];
    }
};