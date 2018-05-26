#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		return help(root, root, 0);
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return help_buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	void flatten(TreeNode* node) {
		if (!node) return;
		flatten(node->left);
		flatten(node->right);

		TreeNode* le = node->left;
		TreeNode* ri = node->right;
		if (le) {
			node->right = le;
			node->left = NULL;
			while (node->right)
				node = node->right;
			node->right = ri;
		}

	}

	bool isValidBST(TreeNode* root) {
		return isValidBST(root, NULL, NULL);
	}

private:
	int help(TreeNode *left, TreeNode* right, int n) {
		if (!left && !right) return n;
		if (!left && right) return help(right->left, right->right, n + 1);
		if (left && !right) return help(left->left, left->right, n + 1);
		return max(help(left->left, left->right, n + 1), help(right->left, right->right, n + 1));
	}

	TreeNode* help_buildTree(vector<int>& preorder, int left1, int right1, vector<int>& inorder, int left2, int right2) {
		if (left1 > right1) return NULL;
		
		TreeNode* root = new TreeNode(preorder[left1]);

		auto pos = find(inorder.begin()+left2, inorder.begin()+right2+1, preorder[left1]);
		int len = pos - inorder.begin();

		root->left = help_buildTree(preorder, left1+1, left1 + len - left2, inorder, left2, len - 1);
		root->right = help_buildTree(preorder, right1 - (right2 - len - 1), right1, inorder, len + 1, right2);
		return root;
	}

	bool isValidBST(TreeNode * root, TreeNode* minNode, TreeNode* maxNode) {
		if (!root) return true;
		if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
			return false;
		return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
	}
};




//***************************** ·Ö¸îÏß ********************************

void print_tree(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	//print_tree(root->left);
	print_tree(root->right);
}

int main() {
	Solution A = Solution();







	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->left->right = new TreeNode(5);
	//root->right->left = new TreeNode(6);
	//root->right->right = new TreeNode(7);
	//A.flatten(root);
	//print_tree(root);


	//vector<int> preorder{ 1,2,4,5,3,6,7 };
	//vector<int> inorder{ 4,2,5,1,6,3,7 };
	//TreeNode* root = A.buildTree(preorder, inorder);
	//print_tree(root);



	//TreeNode * root = new TreeNode(1);
	//root->left = new TreeNode(12);
	//root->left->left = new TreeNode(13);
	//root->right = new TreeNode(24);
	//root->right->right = new TreeNode(232);
	//root->right->right->right = new TreeNode(2323);
	//root = NULL;
	//cout << A.maxDepth(root) << endl;


}