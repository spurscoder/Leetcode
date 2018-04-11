/*
Description : Given an array S of n integers, are there elements a,b,c in S such
that a+b+c=0? Find all unique triplets in the array which gives the sum of zero

*/
class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;
			sort(nums.begin(), nums.end());
			int size = nums.size();
			for (int i = 0; i < size; i++) {
				if (nums[i] > 0) break;
				if (i > 0 && nums[i] == nums[i-1]) continue;
				int shoot = 0 - nums[i];
				int start = i + 1, end = size - 1;
				while (start < end) {
					if (nums[start] + nums[end] == shoot) {
						result.push_back({nums[i], nums[start], nums[end]});
						while (start < end && nums[start] == nums[start+1]) ++start;
						while (start < end && nums[end] == nums[end-1]) --end;
						++start; --end;
					} else
					if (nums[start] + nums[end] < shoot) ++start;
					else --end;
				}
			}
			return result;
		}
};


/* 解法二 */

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> result;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size; ++i) {
			if (nums[i] > 0) break;
			int shoot = 0 - nums[i];
			int l = i + 1, r = size - 1;
			while (l < r) {
				if (nums[l] + nums[r] == shoot) {
					result.insert({nums[i], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l+1]) ++l;
					while (l < r && nums[r] == nums[r-1]) --r;
					++l; --r;
				} else if (nums[l] + nums[r] < shoot) ++l;
				else --r;
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
 	}
};
