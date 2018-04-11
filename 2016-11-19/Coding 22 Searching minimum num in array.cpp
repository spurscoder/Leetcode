/*
问题描述：寻找旋转排序数组中的最小元素
假设一个旋转排序的数组其起始位置是未知的（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。
你需要找到其中最小的元素。
你可以假设数组中不存在重复的元素。


标签： 二分法

*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
          if (nums[left] < nums[right])
            return nums[left];
          int mid = (left + right) / 2;
          if (nums[left] <= nums[mid])
            left = mid + 1;
          else
            right = mid;
        }
        return nums[left];
    }
};
