#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k < 1 || t < 0) return false;
		unordered_map<long, long> map;
		for (int i = 0; i < nums.size(); ++i) {
			long nu = (long)nums[i] - LONG_MIN;
			cout << nu << endl;
			long bucket = nu / ((long)t + 1);
			cout << bucket << endl;

			if (map.find(bucket)!=map.end() || map.find(bucket - 1) != map.end() && nu - map[bucket - 1] <= t || map.find(bucket + 1) != map.end() && map[bucket + 1] - nu <= t)
				return true;
			if (i > k) {
				long last = ((long)nums[i - k] - INT_MIN) / ((long)t + 1);
				map.erase(last);
			}
			map[bucket] = nu;
		}
		return false;
	}

};

int main() {

	Solution A = Solution();

	vector<int> nums{ 2147483647, -2147483647 };
	cout << A.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;

	return 0;
}