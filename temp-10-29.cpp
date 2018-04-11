#include <iostream>
#include <vector>
#include <string>
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
	int calPoints(vector<string>& ops) {
		vector<int> Points;
		long long sum = 0;
		for (int i = 0; i < ops.size(); ++i) {
			string temp = ops[i];
			if (temp == "+") {
				sum += Points[Points.size() - 1] + Points[Points.size() - 2];
				Points.push_back(Points[Points.size() - 1] + Points[Points.size() - 2]);
			}
			else if (temp == "D") {
				sum += Points[Points.size() - 1] * 2;
				Points.push_back(Points[Points.size() - 1] * 2);
			}
			else if (temp == "C") {
				sum -= Points.back();
				Points.pop_back();
			}
			else {
				sum += stoi(temp);
				Points.push_back(stoi(temp));
			}
		}
		return sum;
	}

	int longestUnivaluePath(TreeNode* root) {
		int lup = 0;
		if (root) dfs(root, lup);
		return lup;
	}

	vector<int> constructRectangle(int area) {
		int sq = sqrt(area);
		if (sq*sq == area) return vector<int>{sq, sq};
		for (int i = sq; i >= 1; --i) {
			int temp = area / i;
			if (i * temp == area) return vector<int>{temp, i};
		}
	}

private:
	int dfs(TreeNode* root, int &lup) {
		int l = root->left ? dfs(root->left, lup) : 0;
		int r = root->right ? dfs(root->right, lup) : 0;
		int resl = root->left && root->left->val == root->val ? l + 1 : 0;
		int resr = root->right && root->right->val == root->val ? r + 1 : 0;
		lup = max(lup, resl + resr);
		return max(resl, resr);
	}


};

int main() {
	Solution A = Solution();

	for (int i = 1; i < 16; ++i) {
		vector<int> res = A.constructRectangle(i);
		cout << i << ": " << res[0] << " " << res[1] << endl;
	}
	vector<int> res = A.constructRectangle(10000000);
	cout << res[0] << " " << res[1] << endl;

	//vector<string> ops{ "5", "2", "C", "D", "+" };
	//vector<string> ops1{ "5", "-2", "4", "C", "D", "9", "+", "+" };
	//cout << A.calPoints(ops) << endl;
	//cout << A.calPoints(ops1) << endl;


	return 0;
}