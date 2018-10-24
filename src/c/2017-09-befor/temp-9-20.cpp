#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		temp = new int[target + 1];
		memset(temp, -1, (target + 1) * sizeof(int));
		temp[0] = 1;
		return helper(nums, target);
	}

	int combinationSum4_1(vector<int>& nums, int target) {
		vector<int> temp(target+1, 0);
		temp[0] = 1;
		for (int i = 0; i < target + 1; ++i)
			for (int j = 0; j < nums.size(); ++j)
				if (i >= nums[j])
					temp[i] += temp[i - nums[j]];
		return temp[target];
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return !left ? right : !right ? left : root;
	}

	void moveZeroes(vector<int>& nums) {
		int left = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0 && left != i)
				nums[left++] = nums[i];
		}
		while (left < nums.size()) {
			nums[left++] = 0;
		}
	}

	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	vector<int> findDisappearedNumbers(vector<int>& nums) {
		//int len = nums.size();

		//for (int i = 0; i < len; ++i) {
		//	if (nums[i] == -1) continue;
		//	int temp = nums[i] - 1;
		//	while (nums[temp] != -1) {
		//		int temp1 = nums[temp];
		//		nums[temp] = -1;
		//		temp = temp1 - 1;
		//	}
		//}

		//vector<int> res;
		//for (int i = 0; i < len; ++i)
		//	if (nums[i] != -1)
		//		res.push_back(i+1);
		//return res;

		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			int m = abs(nums[i]) - 1;
			nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
		}
		vector<int> res;
		for (int i = 0; i < len; ++i)
			if (nums[i] > 0) res.push_back(i + 1);
		return res;
	}


private:
	int pathSumFrom(TreeNode* root, int sum) {
		if (!root) return 0;
		return (root->val == sum ? 1 : 0) + pathSumFrom(root->left, sum - root->val) + pathSumFrom(root->right, sum - root->val);
	}

	int *temp;

	int helper(vector<int>& nums, int target) {
		if (temp[target] != -1)
			return temp[target];
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (target >= nums[i])
				res += helper(nums, target - nums[i]);
		}
		temp[target] = res;
		return res;
	}


};

int main() {
	Solution A = Solution();

	vector<int> nums{ 2,3,4,4,5,5,1,2 };
	vector<int> res = A.findDisappearedNumbers(nums);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;


	//vector<int> nums{ 0,1,0,3,12 };
	//A.moveZeroes(nums);
	//for (int i = 0; i < nums.size(); ++i)
	//	cout << nums[i] << endl;


	//vector<int> nums{ 1,2,3 };
	//cout << A.combinationSum4(nums, 32) << endl;

	return 0;
}