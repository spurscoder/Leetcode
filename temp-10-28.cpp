#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int res = nums.size();
		unordered_map<int, int> startIndex, count;
		int len = nums.size(), fre = 0;
		for (int i = 0; i < len; ++i) {
			if (startIndex.count(nums[i]) == 0) startIndex[nums[i]] = i;
			++count[nums[i]];
			if (count[nums[i]] == fre) {
				res = min(i - startIndex[nums[i]] + 1, res);
			}
			if (count[nums[i]] > fre) {
				res = i - startIndex[nums[i]] + 1;
				fre = count[nums[i]];
			}
		}
		return res;
	}

	int countBinarySubstrings(string s) {
		//int res = 0;
		//int zero_l = -2, zero_r = -2;
		//int one_l = -2, one_r = -2;
		//for (int i = 0; i < s.size(); ++i) {
		//	if (s[i] == '0') {
		//		if (i - zero_r > 1) { zero_l = i; zero_r = i; }
		//		else zero_r = i;
		//	}
		//	else {
		//		if (i - one_r > 1) { one_l = i; one_r = i; }
		//		else one_r = i;
		//	}
		//	if (zero_l - one_r == 1 && ((zero_r - zero_l) <= (one_r - one_l))) ++res;
		//	if (one_l - zero_r == 1 && ((one_r - one_l) <= (zero_r - zero_l))) ++res;
		//}
		//return res;

		int prevLen = 0, curLen = 1, res = 0;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] == s[i - 1]) curLen++;
			else {
				prevLen = curLen;
				curLen = 1;
			}
			if (curLen <= prevLen) ++res;
		}
		return res;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		//int row = grid.size(), col = grid[0].size();
		//int area = 0;
		//stack<pair<int, int>> sta;
		//for (int i = 0; i < row; ++i) {
		//	for (int j = 0; j < col; ++j) {
		//		if (grid[i][j] == 1) {
		//			int temp = 1;
		//			grid[i][j] = 0;
		//			if (i > 0 && grid[i - 1][j] == 1) sta.push(make_pair(i - 1, j));
		//			if (j > 0 && grid[i][j - 1] == 1) sta.push(make_pair(i, j - 1));
		//			if (i < row - 1 && grid[i + 1][j] == 1) sta.push(make_pair(i + 1, j));
		//			if (j < col - 1 && grid[i][j + 1] == 1) sta.push(make_pair(i, j + 1));
		//			while (!sta.empty()) {
		//				int l = sta.top().first, r = sta.top().second;
		//				sta.pop();
		//				if (grid[l][r] == 0) continue;
		//				grid[l][r] = 0;						
		//				++temp;
		//				if (l > 0 && grid[l - 1][r] == 1) sta.push(make_pair(l - 1, r));
		//				if (r > 0 && grid[l][r - 1] == 1) sta.push(make_pair(l, r - 1));
		//				if (l < row - 1 && grid[l + 1][r] == 1) sta.push(make_pair(l + 1, r));
		//				if (r < col - 1 && grid[l][r + 1] == 1) sta.push(make_pair(l, r + 1));
		//			}
		//			area = max(area, temp);
		//		}
		//	}
		//}
		//return area;

		int max_area = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j] == 1) max_area = max(max_area, AreaOfIsland(grid, i, j));
		return max_area;

	}
private:

	int AreaOfIsland(vector<vector<int>>& grid, int i, int j) {
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)) {
			grid[i][j] = 0;
			return 1 + AreaOfIsland(grid, i - 1, j) + AreaOfIsland(grid, i + 1, j) + AreaOfIsland(grid, i, j + 1) + AreaOfIsland(grid, i, j - 1);
		}
		return 0;
	}


};

int main() {
	Solution A = Solution();

	vector<vector<int>> nums = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
	{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << A.maxAreaOfIsland(nums) << endl;
	//string s = "10101";
	//cout << A.countBinarySubstrings(s) << endl;

	//vector<int> nums{ 1,2,2,3,1};
	//cout << A.findShortestSubArray(nums) << endl;


	return 0;
}