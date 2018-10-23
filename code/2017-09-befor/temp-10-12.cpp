#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int numDistinct(string s, string t) {
		int slen = s.length();
		int tlen = t.length();

		//vector<vector<int>> matrix(tlen + 1, vector<int>(slen + 1, 0));
		// int[][] matrix = new int[tlen][slen];
		int** matrix = new int*[tlen + 1];
		for (int i = 0; i <= tlen; ++i)
			matrix[i] = new int[slen + 1];

		for (int i = 0; i <= slen; ++i)
			matrix[0][i] = 1;
		for (int i = 1; i <= tlen; ++i)
			matrix[i][0] = 0;

		for (int i = 1; i <= tlen; ++i) {
			for (int j = 1; j <= slen; ++j) {
				if (t[i-1] == s[j-1])
					matrix[i][j] = matrix[i-1][j-1] + matrix[i][j-1];
				else
					matrix[i][j] = matrix[i][j - 1];
			}
		}

		for (int i = 0; i <= tlen; ++i) {
			for (int j = 0; j <= slen; ++j)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
		return matrix[tlen][slen];
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		return helper_PathSum(root, sum, 0);
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> temp;
		if (!root) return res;
		help_pathSum(root, sum, res, temp);
		return res;
	}
private:
	void help_pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> temp) {
		if (!root->left && !root->right) {
			if (sum - root->val == 0) {
				temp.push_back(root->val);
				res.push_back(temp);
			}
			return;
		}

		sum -= root->val;		
		temp.push_back(root->val);

		if (root->left)
			help_pathSum(root->left, sum, res, temp);
		if (root->right)
			help_pathSum(root->right, sum, res, temp);

	}


	bool helper_PathSum(TreeNode* root, int &sum, int cur) {
		if (!root->left && !root->right) {
			if (cur + root->val == sum)
				return true;
			else
				return false;
		}

		cur += root->val;
		
		if (root->left && helper_PathSum(root->left, sum, cur))
			return true;
		if (root->right && helper_PathSum(root->right, sum, cur))
			return true;
		return false;
	}
};

int main() {
	Solution A = Solution();

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);

	vector<vector<int>> res = A.pathSum(root, 1);
	cout << res.size() << endl;

	//cout << A.hasPathSum(root, 1) << endl;



	//string s = "rabbbitit";
	//string t = "rabbit";



	//cout << A.numDistinct(s, t) << endl;



	return 0;
}