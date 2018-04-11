#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxProfit(vector<int> & prices) {
		//int len = prices.size();
		//if (len <= 1) return 0;
		//vector<int> state(len, 0);
		//vector<int> state1(len, 0);
		//vector<int> state2(len, 0);

		//state[0] = 0;
		//state1[0] = -prices[0];
		//state2[0] = INT_MIN;
		//for (int i = 1; i < prices.size(); ++i) {
		//	state[i] = max(state[i - 1], state2[i-1]);
		//	state1[i] = max(state[i - 1] - prices[i], state1[i - 1]);
		//	state2[i] = state1[i - 1] + prices[i];
		//}
		//return state[len - 1] > state2[len - 1] ? state[len - 1] : state2[len - 1];

		int len = prices.size();
		if (len <= 1) return 0;
		int b0 = -prices[0], b1;
		int s0 = 0, s1 = max(0, prices[1]-prices[0]), s2;
		for (int i = 1; i < len; ++i) {
			b1 = max(b0, s0 - prices[i]);
			s2 = max(s1, b1 + prices[i]);
			b0 = b1; s0 = s1; s1 = s2;
		}
		return s2;
	}

	vector<string> removeInvalidParentheses(string s) {

	}

	int rob(TreeNode* root) {
		if (!root) return 0;
		int val = root->val;
		if (root->left)
			val += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			val += rob(root->right->left) + rob(root->right->right);
		return max(val, rob(root->left) + rob(root->right));
	}

	int rob1(TreeNode* root) {
		vector<int> res = dfs(root);
		return max(res[0], res[1]);
	}

	int rob2(TreeNode* root) {
		return robsub(root, new unordered_map<TreeNode*, int>());
	}
private:
	vector<int> dfs(TreeNode* root) {
		if (!root) return vector<int>{0, 0};
		vector<int> left = dfs(root->left);
		vector<int> right = dfs(root->right);
		vector<int> res(2, 0);
		res[0] = root->val + left[1] + right[1];
		res[1] = max(left[1], left[0]) + max(right[1], right[0]);
		return res;
	}

	int robsub(TreeNode* root, unordered_map<TreeNode*, int>* map) {
		if (!root) return 0;
		if (map->find(root) != map->end()) return map->at(root);

		int val = root->val;

		if (root->left)
			val += robsub(root->left->left, map) + robsub(root->left->right, map);
		if (root->right)
			val += robsub(root->right->left, map) + robsub(root->right->right, map);

		val = max(val, robsub(root->left, map) + robsub(root->right, map));
		map->insert(pair<TreeNode*, int>(root, val));
		
		return val;
	}

};


//======================================
int main() {
	Solution A = Solution();

	//vector<int> prices{ 1,2,3,0,2 };
	//cout << A.maxProfit(prices) << endl;

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(1);

	cout << A.rob2(root) << endl;


	return 0;
}