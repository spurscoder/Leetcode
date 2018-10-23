/**
问题描述：平衡二叉树
给定一个二叉树,确定它是高度平衡的。
对于这个问题,一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。

思路：二分法，分治法，递归

*/


/*
关于平衡二叉树的知识
http://blog.csdn.net/niteip/article/details/11840691/
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if (root == NULL)
          return true;
        return treeDepth(root) != -1;
    }
    int treeDepth(TreeNode * root) {
      if (root == NULL)
        return 0;
      int left = treeDepth(root->left);
      int right = treeDepth(root->right);

      if (left == -1 || right == -1 || left-right > 1 || right-left > 1)
        return -1;
      if (left > right)
        return left + 1; // 加上根节点
      return right + 1;
    }
};
