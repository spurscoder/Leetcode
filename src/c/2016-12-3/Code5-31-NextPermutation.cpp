/*
Description: Implement next permutation , which rearranges numbers into the lexicographically
bext greater permutation of numbers.
If such arrangement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

examples:
1,2,3 -- 1,3,2
3,2,1 -- 1,2,3
1,1,5 -- 1,5,1
*/

// !! swap(a, b);
// !! reverse(begin(), end());
/*
1.找到变化点k
2.找到比nums[k]大的数字，离得最远的nums[l]
3.交换k 和l
4.重新排序k+1 到end()

*/

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int k = -1;
    int size = nums.size();
    for (int i = size - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        k = i;
        break;
      }
    }
    if (k == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int l = -1;
    for (int i = size - 1; i > k; --i) {
      if (nums[i] > nums[k]) {
        l = i;
        break;
      }
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin()+k+1, nums.end());
  }
};
