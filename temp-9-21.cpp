#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int hammingDistance(int x, int y) {
		int temp = x ^ y;
		int res = 0;
		while (temp) {
			++res;
			temp &= (temp - 1);
		}
		return res;
	}

	int islandPerimeter(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		int peri = 0;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) {
				if (grid[i][j]) {
					if (i - 1 < 0 || grid[i - 1][j] == 0)
						++peri;
					if (j - 1 < 0 || grid[i][j - 1] == 0)
						++peri;
					if (i + 1 == row || grid[i + 1][j] == 0)
						++peri;
					if (j + 1 == col || grid[i][j + 1] == 0)
						++peri;
				}
			}
		return peri;
	}

	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
	}

	TreeNode* convertBST1(TreeNode* root) {
		if (!root) return NULL;
		helper(root, 0);
		return root;
	}

	TreeNode* convertBST(TreeNode* root) {
		if (!root) return NULL;
		convertBST(root->right);

		root->val += sum;
		sum = root->val;

		convertBST(root->left);

		return root;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		help_diameter(root, res);
		return res;
	}


	bool isSubtree(TreeNode* s, TreeNode* t) {
		bool f1 = false;
		if (!s) return false;
		if (s && t && s->val == t->val)
			f1 = check(s, t);
		return f1 || isSubtree(s->left, t) || isSubtree(s->right, t);
	}


private:
	bool check(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if (!s && t) return false;
		if (s && !t) return false;
		return s->val == t->val && check(s->left, t->left) && check(s->right, t->right);
	}

	int subsetSum(vector<int>& nums, int S) {
		vector<int> temp(S + 1, 0);
		temp[0] = 1;
		for (auto num : nums)
			for (int i = S; i >= num; --i)
				temp[i] += temp[i - num];
		return temp[S];
	}


	int help_diameter(TreeNode* root, int & res) {
		if (!root) return 0;
		int left = help_diameter(root->left, res);
		int right = help_diameter(root->right, res);
		res = max(res, left + right);
		return max(left, right) + 1;
	}

	int sum = 0;
	
	int helper(TreeNode* root, int front) {
		if (!root) return front;
		int right = helper(root->right, front);
		root->val += right;
		int left = helper(root->left, root->val);
		return left;
	}
};

//*************************************************
void show(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	show(root->left);
	show(root->right);
}


//***********************************************************
int main() {
	Solution A = Solution();

	TreeNode* s = new TreeNode(3);
	s->left = new TreeNode(4);
	s->right = new TreeNode(5);
	s->left->left = new TreeNode(1);
	s->left->right = new TreeNode(2);
	s->left->left->left = new TreeNode(3);

	TreeNode * t = new TreeNode(4);
	t->left = new TreeNode(1);
	t->right = new TreeNode(2);

	cout << A.isSubtree(s, t) << endl;



	//TreeNode * root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//// root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->left->right = new TreeNode(5);
	//root->left->left->left = new TreeNode(6);
	//root->left->left->left->left = new TreeNode(6);


	//cout << A.diameterOfBinaryTree(root) << endl;

	//A.convertBST(root);

	//show(root);

	//vector<vector<int>> grid{ {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
	//cout << A.islandPerimeter(grid) << endl;

	//cout << A.hammingDistance(1, 1) << endl;

	return 0;
}