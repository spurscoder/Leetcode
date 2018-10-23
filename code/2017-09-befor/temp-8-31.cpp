#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//	vector<int> searchRange(vector<int>& nums, int target) {
	//		return helper(nums, 0, nums.size() - 1, target);
	//	}
	//private:
	//	vector<int> helper(vector<int>& nums, int left, int right, int target) {
	//		vector<int> res(2, -1);
	//		if (left > right) return res;
	//
	//		if (left == right) {
	//			if (nums[left] == target) {
	//				res[0] = left;
	//				res[1] = right;
	//				return res;
	//			}
	//			else
	//				return res;	
	//		}
	//
	//		int mid = (left + right) / 2;
	//		vector<int> temp1 = helper(nums, left, mid, target);
	//		vector<int> temp2 = helper(nums, mid+1, right, target);
	//		res[0] = temp1[0] != -1 ? temp1[0] : temp1[1] != -1 ? temp1[1] : temp2[0] != -1 ? temp2[0] : temp2[1] != -1 ? temp2[1] : -1;
	//		res[1] = temp2[1] != -1 ? temp2[1] : temp2[0] != -1 ? temp2[0] : temp1[1] != -1 ? temp1[1] : temp1[0] != -1 ? temp1[0] : -1;
	//		return res;
	// 	}
	//
	// Solution 2
		//vector<int> searchRange(vector<int>& nums, int target) {
		//	int i = 0, j = nums.size() - 1;
		//	vector<int> res(2, -1);
		//	if (!nums.size()) return res;
		//	// Search for the left one
		//	while (i < j) {
		//		int mid = (i + j) / 2;
		//		if (nums[mid] < target) i = mid + 1;
		//		else j = mid;
		//	}
		//	if (nums[i] != target) return res;
		//	else res[0] = i;
		//
		//	// Search for the right one
		//	j = nums.size() - 1;
		//	while (i < j) {
		//		int mid = (i + j) / 2 + 1;
		//		if (nums[mid] > target) j = mid - 1;
		//		else i = mid;
		//	}
		//	res[1] = j;
		//	return res;
		//}
	// Solution 3
		//vector<int> searchRange(vector<int>& nums, int target) {
		//	auto bounds = equal_range(nums.begin(), nums.end(), target);
		//	if (bounds.first == bounds.second)
		//		return { -1, -1 };
		//	return { bounds.first - nums.begin(), bounds.second - nums.begin() - 1 };

	// Solution 4
	vector<int> searchRange(vector<int>& nums, int target) {
		int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		if (lo == nums.size() || nums[lo] != target)
			return { -1, -1 };
		int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
		return { lo, hi };
	}

	bool isBadVersion(int verison);
	int firstBadVersion(int n) {
		int i = 1, j = n;
		while (i < j) {
			int mid = (i + j) / 2;
			if (!isBadVersion(mid)) i = mid + 1;
			else j = mid;
		}
		return i;
	}

	//int longestValidParentheses(string s) {
	//	int res = INT_MIN;
	//	vector<int> stack;
	//	for (int i = 0; i < s.size(); ++i) {
	//		if (!stack.size())
	//			stack.push_back(i);
	//		else {
	//			int j = stack.back();
	//			if (s[j] == '(' && s[i] == ')')
	//				stack.pop_back();
	//			else
	//				stack.push_back(i);
	//		}
	//	}
	//	if (!stack.size()) return s.size();
	//	else {
	//		int left = 0, right = s.size();
	//		while (stack.size()) {
	//			left = stack.back();
	//			stack.pop_back();
	//			res = max(res, right - left - 1);
	//			right = left;
	//		}
	//		res = max(res, right);
	//	}
	//	return res;
	//}
	// Solution 2 using DP 
	int longestValidParentheses(string s) {
		//if (s.size() <= 1) return 0;
		//int res = 0;
		//vector<int> longest(s.size(), 0);
		//for (int i = 1; i < s.size(); ++i) {
		//	if (s[i] == ')') {
		//		if (s[i - 1] == '(') {
		//			longest[i] = (i - 2) >= 0 ? (longest[i - 2] + 2) : 2;
		//			res = max(longest[i], res);
		//		}
		//		else {
		//			if (i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(') {
		//				longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
		//				res = max(longest[i], res);
		//			}
		//		}
		//	}
		//}
		//return res;
		//
		//if (s.length() <= 1) return 0;
		//int res = 0;
		//vector<int> longest(s.size(), 0);
		//for (int i = 1; i < s.length(); ++i) {
		//	if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(') {
		//		longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
		//		res = max(longest[i], res);
		//	}
		//}
		//return res;

		stack<int> stk;
		stk.push(-1);
		int maxL = 0;
		for (int i = 0; i < s.size(); ++i) {
			int t = stk.top();
			if (t != -1 && s[i] == ')' && s[t] == '(') {
				stk.pop();
				maxL = max(maxL, i - stk.top());
			}
			else
				stk.push(i);
		}
		return maxL;
	}
	
	int searchInsert(vector<int>& nums, int target) {
		int i = 0, j = nums.size();
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}
		return i;
	}

	int guess(int num);
	int guessNumber(int n) {
		int i = 1, j = n;
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (guess(mid) == -1) i = mid + 1;
			else j = mid;
		}
		return i;
	}

	int trap(vector<int>& height) {
		//int left = 0, right = height.size() - 1;
		//int res = 0;
		//int maxleft = 0, maxright = 0;
		//while (left <= right) {
		//	if (height[left] <= height[right]) {
		//		if (height[left] >= maxleft) maxleft = height[left];
		//		else 
		//	}
		//}
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r) {
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}

	bool help(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;
		if (!left && right) return false;
		if (left && !right) return false;
		if (left->val != right->val)
			return false;
		else
			return (help(left->left, right->right) && help(left->right, right->left));
	}
	bool isSymmetric(TreeNode* root) {
		return help(root, root);
	}
};


int main() {
	Solution A = Solution();

	TreeNode * root = new TreeNode(12);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);

	root = NULL;

	cout << A.isSymmetric(root);


	//vector<int> height{ 0,1,1,2,1 };
	//cout<< A.trap(height);
	//
	//vector<int> nums{ };
	//cout << A.searchInsert(nums, 2) << endl;
	//cout << A.searchInsert(nums, 0) << endl;
	//cout << A.searchInsert(nums, 10) << endl;
	//cout << A.searchInsert(nums, 5) << endl;
	//cout << A.searchInsert(nums, 9) << endl;
	//string s1 = "(()";
	//string s2 = ")()())";
	//string s3 = "()()";
	//string s4 = "(())";
	//string s5 = "()(())(()";
	//string s6 = "(())())(()()()()(()(()())()))()";
	//cout << A.longestValidParentheses(s5) << endl;
	//vector<int> nums{ 5,6,6,7,7,98 };
	//vector<int> res = A.searchRange(nums, 4);
	//cout << res[0] << "  " << res[1] << endl;

	return 0;
}