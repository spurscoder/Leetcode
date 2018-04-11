/**
问题描述：寻找旋转排序数组中的最小值 ||
假设一个旋转排序的数组其起始位置是未知的（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。
你需要找到其中最小的元素。
数组中可能存在重复的元素

标签： 二分法 分治法

思路： 二分查找时候，如果nums[mid] > nums[right] 则最小值在mid和right之间
                  如果nums[mid] < nums[left] 则最小值在left和mid之间
                  如果nums[left] = nums[mid] = nums[right] 则情况不确定，此时right--即可
                  eg.
                  [1,2,1,1,1]
                  [3,2,3,3,3]

*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0;
        int right = num.size() - 1;

        while(left < right)
        {
          if (num[left] < num[right])
            return num[left];
          int mid = (left + right) / 2;
          if (num[mid] > num[right])
            left = mid + 1;
          else if (num[mid] < num[left])
            right = mid;
          else
            right--;
        }
        return num[left];
    }
};
