#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) return nums[0];
		if (len == 2) return max(nums[0], nums[1]);

		int rob1 = 0, notrob1 = 0;
		int rob2 = 0, notrob2 = 0;
		for (int i = 0; i < len; ++i) {
			if (i > 0) {
				int cur1 = notrob1 + nums[i];
				notrob1 = max(notrob1, rob1);
				rob1 = cur1;
			}
			if (i < len - 1) {
				int cur2 = notrob2 + nums[i];
				notrob2 = max(notrob2, rob2);
				rob2 = cur2;
			}
		}
		return max(max(rob1, notrob1), max(rob2, notrob2));
	}

	int findIntegers(int num) {
		vector<int> f(32, 0);
		f[0] = 1; f[1] = 2;
		for (int i = 2; i < 32; ++i)
			f[i] = f[i - 1] + f[i - 2];
		int ans = 0, pre = 0;
		for (int k = 31; k >= 0; --k) {
			if (num & (1 << k)) {
				ans += f[k];
				if (pre) return ans;
				pre = 1;
			}
			else
				pre = 0;
		}
		return ans + 1;
	}

	int countSubstring(string s) {
		int res = 0, len = s.length();
		for (int i = 0; i < len; ++i) {
			for (int l = i, r = i; l >= 0 && r < len && s[l] == s[r]; --l, ++r) ++res;
			for (int l = i, r = i + 1; l >= 0 && r < len && s[l] == s[r]; --l, ++r) ++res;
		}
		return res;
	}

	int longestPalindromeSubseq(string s) {
		int res = 0, len = s.size();
		for (int i = 0; i < len; ++i) {
			for (int l = i, r = i; l >= 0 && r < len)
		}
	}
};


int main() {
	Solution A = Solution();

	string s = "a";
	cout << A.countSubstring(s) << endl;

	//vector<int> nums{ 1 , 2, 3, 4, 5};
	//cout << A.rob(nums) << endl;

	return 0;
}