#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		//return fmod(log10(n) / log10(3), 1) == 0;
		return (n > 0 && 1162261467 % n == 0);
	}

	bool isPowerOfFour(int num) {
		//return fmod(log10(num) / log10(4), 1) == 0;
		return (num > 0) && (num&(num - 1) == 0) && ((num & 0x55555555) == num);
	}

	string reverseVowels(string s) {
		int i = 0, j = s.length() - 1;
		while (i < j) {
			i = s.find_first_of("aeiouAEIOU", i);
			j = s.find_last_of("aeiouAEIOU", j);
			if (i < j) {
				swap(s[i++], s[j--]);
			}
		}
		return s;
	}

	int findPairs(vector<int>& nums, int k) {
		//sort(nums.begin(), nums.end());
		//int res = 0;
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (i > 0 && nums[i] == nums[i - 1])
		//		continue;
		//	for (int j = i + 1; j < nums.size(); ++j) {
		//		if (nums[j] - nums[i] == k) {
		//			++res; break;
		//		}
		//		else if (nums[j] - nums[i] > k)
		//			break;
		//	}
		//}
		//return res;

		if (k < 0) return 0;
		unordered_map<int, int> mp;
		for (int n : nums) mp[n] ++;
		int cnt = 0;
		for (auto p : mp)
			if ((k && mp.count(p.first + k)) || (!k && p.second > 1)) ++cnt;
		return cnt;
	}


	int integerBreak(int n) {
		if (n == 2 || n == 3) return n - 1;
		int product = 1;
		while (n > 4) {
			product *= 3;
			n -= 3;
		}
		product *= n;

		return product;
	}

	void qSort(int nums[], int n) {
		if (n <= 0) return;
		int cur = nums[0];
		int i = 0, j = n - 1;
		while ( i < j ) {
			while (i < j && nums[j] >= cur) --j;
			nums[i] = nums[j];
			while (i < j && nums[i] <= cur) ++i;
			nums[j] = nums[i];
		}
		nums[i] = cur;
		qSort(nums, i);
		qSort(nums + i + 1, n - i - 1);
	}

	void bubbleSort(int nums[], int n) {
		if (n <= 0) return;
		//for (int i = n - 1; i > 0; --i) {
		//	for (int j = 0; j < i; ++j) {
		//		if (nums[j] > nums[j + 1])
		//			swap(nums[j], nums[j + 1]);
		//	}
		//}

		bool flag = true;
		while (flag) {
			flag = false;
			n--;
			for (int j = 0; j < n; ++j) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
					flag = true;
				}
			}
		}


	}


private:


};

int main() {
	Solution A = Solution();

	//int nums[] = { 5,4,3,2,1 };
	//int n = 5;
	//A.bubbleSort(nums, n);
	//for (int i = 0; i < n; ++i)
	//	cout << nums[i] << endl;


	int nums[] = { 5,1,2,3,4,0 };
	int n = 6;
	A.qSort(nums, n);
	for (int i = 0; i < n; ++i)
		cout << nums[i] << endl;


	//cout << A.integerBreak(2) << endl;
	//cout << A.integerBreak(10) << endl;
	//cout << A.integerBreak(11) << endl;
	//cout << A.integerBreak(58) << endl;

	//vector<int> nums{ 1,3,1,5,4 };
	//vector<int> nums1{ 3,1,4,1,5 };
	//cout << A.findPairs(nums, 0) << endl;
	//cout << A.findPairs(nums1, 2) << endl;
	//cout << A.findPairs(nums, 2) << endl;

	//cout << A.reverseVowels("hello") << endl;
	//cout << A.reverseVowels("leetcode") << endl;
	//cout << A.reverseVowels("aeiou") << endl;
	//cout << A.reverseVowels("") << endl;
	//cout << A.reverseVowels("a") << endl;
	//cout << A.reverseVowels("aA") << endl;

	//cout << A.isPowerOfFour(4) << endl;
	//cout << A.isPowerOfFour(8) << endl;
	//cout << A.isPowerOfFour(5) << endl;

	//cout << A.isPowerOfThree(3) << endl;
	//cout << A.isPowerOfThree(4) << endl;
	//cout << A.isPowerOfThree(2) << endl;

	return 0;
}