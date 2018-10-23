/*
Given an intger array nums, find the sum of the elements between indices i
and j (i<=j), inclusive.

Note :
  1. You may assume that the array does not change.
  2. There are many calls to sumRange function.
*/
class NumArray {
private:
  int length;
  vector<int> sums;
public:
  NumArray(vector<int> & nums) {
    length = nums.size();
    if (length == 0) return;

    sums = vector<int>(length+1, 0);
    for (int i = 1; i < length ; i++)
      sums[i] = nums[i] + sums[i - 1];
  }
  int sumRange(int i, int j) {
    return sums[j] - sums[i];
  }
};


/*
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};
*/
