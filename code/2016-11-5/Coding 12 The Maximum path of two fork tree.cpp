/*问题描述 ：
给出一棵二叉树，寻找一条路径使其路径和最大，
路径可以在任一节点中开始和结束（路径和为两个节点之间所在路径上的节点权值之和）
*/

/**思路：
分治法和递归思路
*/


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int ret = INT_MIN;
        onePath(root,ret);
        return ret;
    }
    int onePath(TreeNode* root,int &ret)
    {
        if(root==nullptr)
            return 0;
        int l = onePath(root->left,ret);
        int r = onePath(root->right,ret);
        ret = max(ret,max(0,l)+max(0,r)+root->val);
        return max(0,max(l,r))+root->val;
    }
};
