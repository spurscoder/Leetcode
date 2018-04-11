/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2 return [1,2];

Note:
  1. You may assume k is always valid, 1 <= k <= number of unique elements.
  2. Your algorithm's time complexity must be better than O(nlogn),
      where n is the array's size.
*/

/**

好代码，细细品味


**/


class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> fre;
    for (int i:nums) fre[i]++;

    vector<int> res;
    priority_queue<pair<int, int>> pq;
    for (auto it = fre.begin(); it != fre.end(); it++) {
      pq.push(make_pair(it->second, it->first));
      if (pq.size() > (int)fre.size()-k) {
        res.push_back(pq.top().second);
        pq.pop();
      }
    }
    return res;
  }
};
