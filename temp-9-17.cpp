#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDistance(string word1, string word2) {
		//int len1 = word1.size();
		//int len2 = word2.size();
		//vector<vector<int>> res(len1+1, vector<int>(len2+1, 0));

		//for (int i = 1; i <= len1; ++i)
		//	for (int j = 1; j <= len2; ++j) {
		//		if (word1[i-1] == word2[j-1])
		//			res[i][j] = res[i - 1][j - 1] + 1;
		//		else
		//			res[i][j] = max(res[i - 1][j], res[i][j - 1]);
		//	}
		//return len1 + len2 - 2 * res[len1][len2];

		int len1 = word1.size();
		int len2 = word2.size(); 
		if (len1 == 0 || len2 == 0) return len1 == 0 ? len2 : len1;
		vector<vector<int>> res(len1 + 1, vector<int>(len2 +1 , 0));
		for (int i = 0; i <= len1; ++i)
			res[i][0] = i;
		for (int j = 0; j <= len2; ++j)
			res[0][j] = j;
		for (int i = 1; i <= len1; ++i)
			for (int j = 1; j <= len2; ++j) {
				if (word1[i - 1] == word2[j - 1])
					res[i][j] = res[i - 1][j - 1];
				else
					res[i][j] = min(res[i - 1][j] + 1, min(res[i - 1][j - 1] + 2, res[i][j - 1] + 1));
			}
		return res[len1][len2];
	}

	string multiply(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> res(len1 + len2, 0);
		for (int i = len1 - 1; i >= 0; --i)
			for (int j = len2 - 1; j >= 0; --j) {
				int mul = (num1[i] - '0') * (num2[j] - '0');
				int p1 = i + j, p2 = p1 + 1;
				int sum = mul + res[p2];

				res[p1] += sum / 10;
				res[p2] = sum % 10;
			}
		for (int i = 0; i < len1 + len2; ++i)
			cout << res[i] << endl;

		string s;
		bool flag = false;
		for (int i = 0; i < len1 + len2; ++i) {
			if (res[i] != 0)
				flag = true;
			if (flag)
				s += (res[i] + '0');
		}
		return s == "" ? "0" : s;
	}

	string reverseString(string s) {
		string res;
		for (int i = s.size(); i >= 0; --i)
			res += s[i];
		return res;
	}

	TreeNode * mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t2) return t1;
		if (!t1) return t2;

		t1->val += t2->val;	
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;	
	}

	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k)
			reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
		return s;
	}

private:

};

void show(TreeNode * root) {
	if (root == NULL)
		return;
	cout << root->val << endl;
	show(root->left);
	show(root->right);
}

int main() {
	Solution A = Solution();

	string s = "1231234564561233";
	cout << A.reverseStr(s, 3) << endl;

	//string num1 = "923";
	//string num2 = "9";

	//cout << A.multiply(num1, num2) << endl;




	//TreeNode * t1 = new TreeNode(1);
	//t1->left = new TreeNode(3);
	//t1->right = new TreeNode(2);
	//t1->left->left = new TreeNode(5);

	//TreeNode * t2 = new TreeNode(2);
	//t2->left = new TreeNode(1);
	//t2->right = new TreeNode(3);
	//t2->left->right = new TreeNode(4);
	//t2->right->right = new TreeNode(7);

	//t1 = NULL;
	//t2 = NULL;

	//TreeNode * res = A.mergeTrees(t1, t2);

	//show(res);



	//string word1 = "eat";
	//string word2 = "seaaa";

	//cout << A.minDistance(word2, word1) << endl;


	return 0;
}