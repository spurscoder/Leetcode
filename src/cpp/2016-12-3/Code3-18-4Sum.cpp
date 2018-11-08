/*
Description:Given an array S of n integers, are there elements a, b, c, and d in
S such that a + b + c + d = target? find all unique quadruplets in the array which
gives the sum of target/

Array, Hash Table, Two Pointers,
*/
// O（N^3）
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> result;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      for (int j = i+1; j < size; ++j) {
        int l = j + 1, r = size - 1;
        int left = target - nums[i] - nums[j];
        while (l < r) {
          if (nums[l] + nums[r] == left) {
            result.insert({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l+1]) ++l;
            while (l < r && nums[r] == nums[r-1]) --r;
            ++l; --r;
          } else if (nums[l] + nums[r] < left) ++l;
          else --r;
        }
      }
    }
    return vector<vector<int>>(result.begin(), result.end());
  }
};

// 时间复杂度为O（N^2） 空间复杂度为O(N)
// 采用分治思想，先对数组预处理，求得元素两两之和，然后采用2Sum算法思想遍历数组求得四个数字之和。

/*
1.两两求和，将x,y,sum存入数组SUM中
2.以SUM为标准排序
  bool myfunction (int i,int j) { return (i<j); }
  std::sort (myvector.begin()+4, myvector.end(), myfunction);
  使用自己的排序函数，按照自己的方法进行排序
3.采用两两求和的方法
*/

/*
O(N^2)
http://blog.csdn.net/doc_sgl/article/details/12462151
使用hashtable方法排序
*/
