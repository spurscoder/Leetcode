/*问题描述
假设一个旋转排序的数组其起始位置是未知的
（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。
你需要找到其中最小的元素。
数组中可能存在重复的元素。
*/

/*思路
二分法不如直接遍历！！

*/
class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int size = num.size();
        if (size == 0) return NULL;
        int min = num[0];
        for (int i = 0;i < size; i++) {
            if (min > num[i])
                min = num[i];
        }
        return min;
    }
};