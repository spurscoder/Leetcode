/*
问题描述：把排序数组转换为高度最小的二叉搜索树
给一个排序数组（从小到大），将其转换为一棵高度最小的排序二叉树。

思路：
可以直接取中间值作为根节点，之后递归选取相应的中间值作为子树的根节点

挑战：可能有多个答案，返回任意一个即可
递归，二叉树

参考：http://blog.csdn.net/lyy_hit/article/details/49660671
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.empty())
          return NULL;
        int start = 0, end = A.size() - 1;
        int mid = (start + end) / 2;
        TreeNode *Head = new TreeNode(A[mid]);
        Head->left = sortedArrayToBSTCore(A, start, mid - 1);
        Head->right = sortedArrayToBSTCore(A, mid + 1, end);
        return Head;
    }
    TreeNode *sortedArrayToBSTCore(vector<int> &A, int start, int end)
    {
      if (start > end)
        return NULL;
      int mid = (start + end) / 2;
      TreeNode *Head = new TreeNode(A[mid]);
      Head->left = sortedArrayToBSTCore(A, start, mid - 1);
      Head->right = sortedArrayToBSTCore(A, mid + 1, end);
      return Head;
    }
};
