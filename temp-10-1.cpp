#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			sta.push(root);
			root = root->left;
		}
	}
	bool hasNext() {
		return !sta.empty();
	}

	int next() {
		TreeNode* res = sta.top();
		sta.pop();
		int ne = res->val;
		if (res->right) {
			res = res->right;
			while (res) {
				sta.push(res);
				res = res->left;
			}
		}
		return ne;
	}
private:
	stack<TreeNode*> sta;
};

class Solution {
public:
	string reverseWords(string s) {
		//string temp = "";
		//string res = "";
		//for (int i = s.length() - 1; i >= 0; --i) {
		//	if (s[i] == ' ') {
		//		res = ' ' + temp + res;
		//		temp.clear();
		//	}
		//	else {
		//		temp += s[i];
		//	}
		//}
		//res = ' ' + temp + res;
		//return res.substr(1);

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] != ' ') {
				int j = i;
				for (; j < s.length() && s[j] != ' '; ++j) {}
				reverse(s.begin() + i, s.begin() + j);
				i = j - 1;
			}
		}
		return s;

	}

	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int res = 0;
		for (int i = 0; i < len; i += 2)
			res += nums[i];
		return res;
	}

	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i) {
			for (int j = i; j < n - 1 - i; ++j) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = temp;
			}
		}
	}
private:

};

int main() {
	Solution A = Solution();

	vector<vector<int>> matrix{ {1,2,3}, {4,5,6},{7,8,9} };
	vector<vector<int>> matrix1{ {5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16} };
	A.rotate(matrix1);
	A.rotate(matrix1);
	for (int i = 0; i < matrix1.size(); ++i) {
		for (int j = 0; j < matrix1.size(); ++j)
			cout << matrix1[i][j];
		cout << endl;
	}


/*
	vector<int> nums{ 1,4,3,2 };
	cout << A.arrayPairSum(nums) << endl;*/

	//string s = "Let's take LeetCode contest";

	//cout << A.reverseWords(s) << endl;


	//TreeNode *root = new TreeNode(5);
	//root->left = new TreeNode(3);
	//root->right = new TreeNode(7);
	//root->left->left = new TreeNode(1);
	//root->left->right = new TreeNode(4);
	//root->right->left = new TreeNode(6);
	//root->right->right = new TreeNode(8);

	//BSTIterator B = BSTIterator(root);

	//while (B.hasNext()) cout << B.next() << endl;

	return 0;
}