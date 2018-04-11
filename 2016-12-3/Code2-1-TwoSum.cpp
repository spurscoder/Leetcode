/*
Description: Given an array of integers, return indices of the two numbers such
that they add up to a specific target.
you may assume that each input would have exactly one Solution.

*/
// O（N^2）-------------------------------------------

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      for (int j = i + 1; j < size; ++j) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          break;
        }
      }
    }
    return result;
  }
};


// O（N）  -------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        map<int, int> m;
        if (nums.size() < 2)
            return result;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            m[nums[i]] = i;

        map<int, int>::iterator it;
        for (int i = 0; i < size; i++) {
            if ((it = m.find(target - nums[i])) != m.end())
            {
                if (i == it->second) continue;
                result.push_back(i);
                result.push_back(it->second);
                break;
            }
        }
        return result;
    }
};
