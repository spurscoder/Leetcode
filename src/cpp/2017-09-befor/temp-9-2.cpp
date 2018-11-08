#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// DP. maxSubArray(nums, i) = maxSubArray(nums, i - 1) ? maxSubArray(nums, i - 1) : nums[i];
		// This is the format of the sub problem
		// the state of the sub problem
		/*int n = nums.size();
		int* dp = new int(n);
		dp[0] = nums[0];
		int res = dp[0];

		for (int i = 0; i < n; ++i) {
			dp[i] = nums[i] + (dp[i - 1] ? dp[i - 1] : 0);
			res = max(dp[i], res);
		}
		return res;*/

		int res = nums[0], sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			res = max(res, sum);
			sum = max(sum, 0);
		}
		return res;
	}

	bool canJump(vector<int>& nums) {
		//vector<int> temp(nums.size(), 0);
		//temp[0] = 1;
		//for (int i = 0; i < nums.size() - 1; ++i) {
		//	if (temp[i]) {
		//		for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
		//			temp[i + j] = 1;
		//		}
		//	}
		//}
		//return temp[nums.size() - 1];

		// This is others solution
		//int i = 0; 
		//for (int reach = 0; i < nums.size() && i <= reach; ++i) {
		//	reach = max(reach, nums[i] + i);
		//}
		//return i == nums.size();

		// Solution 2
		int last = nums.size() - 1;
		for (int i = last - 1; i >= 0; --i)
			if (i + nums[i] >= last) last = i;
		return last == 0;
	}
	
	int uniquePaths(int m, int n) {
		//vector<vector<int>> res(m, vector<int>(n, 1));
		//for (int i = 1; i < m; ++i)
		//	for (int j = 1; j < n; ++j)
		//		res[i][j] = res[i - 1][j] + res[i][j - 1];
		//for (int i = 0; i < m; ++i) {
		//	for (int j = 0; j < n; ++j)
		//		cout << res[i][j] << " ";
		//	cout << endl;
		//}
		//return res[m - 1][n - 1];

		// 组合数学的方法
		// 从m+n-2 中取出m-1个作为竖着的
		//if (m <= 0 || n <= 0) return 0;
		//long long res = 1;
		//for (int i = n; i < n + m - 1; ++i)
		//	res = res * i / (i - n + 1);
		//return (int)res;

		if (m > n) return uniquePaths(n, m);
		vector<int> res(m, 1);
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				res[j] += res[j - 1];
		return res[m - 1];
	}

	int climbStairs(int n) {
		int first = 0, second = 1, third = 1;
		for (int i = 1; i < n; ++i) {
			first = second;
			second = third;
			third = first + second;
		}
		return third;
	}

	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1, imax = res, imin = res; i < nums.size(); ++i) {
			if (nums[i] < 0)
				swap(imax, imin);
			imax = max(nums[i], imax*nums[i]);
			imin = min(nums[i], imin*nums[i]);

			res = max(res, imax);
		}
		return res;
	}

private:



};



//******************************* 分割线 *****************************

int main() {
	Solution A = Solution();

	cout << A.climbStairs(1) << endl;
	cout << A.climbStairs(2) << endl;
	cout << A.climbStairs(3) << endl;
	cout << A.climbStairs(10) << endl;




	//cout << A.uniquePaths(1, 1) << endl;
	//cout << A.uniquePaths(2, 2) << endl;
	//cout << A.uniquePaths(10,10) << endl;

	//vector<int> nums{ 2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6 };
	//vector<int> nums1{ 3,2,1,0,4 };
	//vector<int> nums2{ 2,3,1,1,4 };
	//vector<int> nums3{ 0,1 };
	//cout << A.canJump(nums) << endl;
	//cout << A.canJump(nums1) << endl;
	//cout << A.canJump(nums2) << endl;
	//cout << A.canJump(nums3) << endl;
	return 0;
}