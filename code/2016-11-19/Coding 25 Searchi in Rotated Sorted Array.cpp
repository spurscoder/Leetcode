/**
Description: Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

challenge: O(logN)

二分查找，主要是确定单调递增的那一段区间

*/


class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        int mid;
        while (left <= right)
        {
          mid = (left + right) / 2;
          if(A[mid] == target)
            return mid;
          if (A[mid] > A[left])
          {
            if (A[mid] >= target && target >= A[left])
              right = mid - 1;
            else
              left = mid + 1;
          }
          else
          {
            if (A[mid] <= target && target <= A[r])
              left = mid + 1;
            else
              right = mid - 1;
          }
        }
        return -1;
    }
};
