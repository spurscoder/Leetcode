/*
Input array is sorted
Description: Given an array of integers that is already sorted in ascending order,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up
to the target, where index1 must be less than index2. please note that your returned
answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.
*/

// O (N)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> result;
      int size = numbers.size();
      if (size < 2 || numbers[0] > target) return result;
      int l = 0, r = size - 1;
      while (l < r) {
        int temp = numbers[l] + numbers[r];
        if (temp == target) {
          result.push_back(l+1);
          result.push_back(r+1);
          return result;
        } else if (temp < target) ++l;
        else --r;
      }
      return result;
    }
};


//  Others O(分治法)

class Solution {
  vector<int> twoSum(vector<int>& numbers, int targer) {
    if (numbers.empty()) return {};
    int size = numbers.size();
    for (int i = 0 ; i < size-1; ++i) {
      int start = i + 1, end = size - 1, temp = target - numbers[i];
      while (start <= end) {
        int m = start + (end - start) / 2;
        if (numbers[m] == temp) return {i+1, m+1};
        else if (numbers[m] > temp) end = m - 1;
        else start = m + 1;
      }
    }
    return {};
  }
};
