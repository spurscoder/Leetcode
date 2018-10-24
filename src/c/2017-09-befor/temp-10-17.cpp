#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int j = nums.size() - 1, i = 0;
		int mid = (i + j) / 2;

		if (j == -1) return NULL;

		TreeNode* root = new TreeNode(nums[mid]);

		root->left = sortedArrayToBST(nums, i, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, j);

		return root;
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		set<vector<int>> temp;
		set<vector<int>> temp1;
		for (auto num : nums) {
			for (auto it : temp) {
				if (it.back() <= num) {
					it.push_back(num);
					temp1.insert(it);
				}
			}
			temp.insert(vector<int>{num});
			temp.insert(temp1.begin(), temp1.end());
		}
		vector<vector<int>> res;
		for (auto it : temp) {
			if (it.size() < 2) continue;
			res.push_back(it);
		}
		return res;
	}





private:

	TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
		if (i > j) return NULL;
		int mid = (i + j) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, i, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, j);
		return root;
	}


};

void show(TreeNode* root) {
	if (root == NULL) return;
	show(root->left);
	cout << root->val << endl;
	show(root->right);
}

int main() {
	Solution A = Solution();

	vector<int> nums{1,4};
	vector<vector<int>> res = A.findSubsequences(nums);
	for (auto it : res) {
		for (auto mem : it) {
			cout << mem << " ";
		}
		cout << endl;
	}

	//set<vector<int>> temp;
	//temp.insert(vector<int>{1, 2});
	//temp.insert(vector<int>{1, 2});
	//temp.insert(vector<int>{3, 4});
	//for (auto it : temp) {
	//	for (auto mem : it) {
	//		cout << mem << " ";
	//	}
	//	cout << endl;
	//}


	//vector<int> nums{ 1,2,3,4,5 };
	//show(A.sortedArrayToBST(vector<int>{1}));



	return 0;
}