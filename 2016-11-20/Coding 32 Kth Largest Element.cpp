/*
Description: Kth Largest Element
Find K-th largest element in an array

Challenge:
O(n)time, O(1)extra,memory

Tags:
Quick sort, Sort

运用了快速排序算法的思想

*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
          int left = start, right = end;
          int key = nums[left];
          while (left < right) {
            while (left < right && nums[right] < key) --right;
            nums[left] = nums[right];
            while (left < right && nums[left] >= key) ++left;
            nums[right] = nums[left];
          }
          nums[left] = key;
          if (left == k - 1) return nums[k - 1];
          else if (left > k - 1) end = left - 1;
          else start = left + 1;
        }
        return nums[k - 1];
    }
};
