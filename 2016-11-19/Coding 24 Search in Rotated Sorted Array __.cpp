/*
Description: Search in Rotated Sorted Array ||

Follow up for Search in Rotated Sorted Array:
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.

binary search , sorted array , array

分析：有重复数据还是很蛋疼的，重点在于消重，要使得A[l]严格大于A[r],
      这样就可以继续判断区间的单调性，从而二分
*/


class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        int mid;

        while (left <= right)
        {
          while (left < right && A[left] == A[right])
            left++;

          mid = (left + right) / 2;
          if (A[mid] == target)
            return true;

          if (A[left] < A[right])
          {
            if (A[mid] < target)
              left = mid + 1;
            else
              right = mid - 1;
          } else
          if (A[mid] >= A[left])
          {
            if (A[mid] >= target && target >= A[left])
              right = mid - 1;
            else
              left = mid + 1;
          }
          else
          {
            if (A[mid] <= target && target <= A[right])
              left = mid + 1;
            else
              right = mid - 1;
          }
        }
        return false;
    }
};
