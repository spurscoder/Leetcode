/*问题描述：不同的二叉树 ||
给出n,生成所有由1...n为节点组成的不同的二叉查找树
*/
/**
给出n=3，生成所有5中不同形态的二叉查找树。
1         3     3       2    1
 \       /     /       / \    \
  3     2     1       1   3    2
 /     /       \                \
2     1         2                3
*/
/*思路
动态规划的方法
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
      * @paramn n: An integer
      * @return: A list of root
      */
     vector<TreeNode *> generateTrees(int n) {
         // write your code here
         return generateTrees(1, n+1);
     }
 private:
     vector<TreeNode *> generateTrees(int start, int end) {
       vector<TreeNode *> subTree;
       if (start >= end) {
         subTree.push_back(NULL);
         return subTree;
       }
       if (start == end-1) {
         subTree.push_back(new TreeNode(start));
         return subTree;
       }

       for (int i = start; i < end; i++) {
         vector<TreeNode *> left = generateTrees(start, i);
         vector<TreeNode *> right =generateTrees(i+1, end);
         for (int j = 0; j < left.size(); j++)
          for (int k = 0; k < right.size(); k++) {
            TreeNode * root = new TreeNode(i);
            root->left = left[j];
            root->right = right[k];
            subTree.push_back(root);
          }
       }
       return subTree;
     }
 };

























--------------------------------------------------------------------------

/**不同的二叉查找树
给出 n，问由 1...n 为节点组成的不同的二叉查找树有多少种？

就是把所有点都当一次root看待，当i=root时候，小于i的二叉树的个数乘以大于i的数的个数 = 当i为根时候的二叉树
个数。依次求和得到所有的二叉树的状态。
思路：动态规划 卡特兰数

实际上二叉查找树的数目就满足卡特兰数的递推公式

*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n == 1 || n == 0)
          return 1;
        int *num = new int[n+1];
        num[0] = num[1] = 1;
        for (int i = 2;i <= n;i++) {
          for(int j = 1;j <= i;j++) {
            num[i] += num[j-1]*num[i-j];
          }
        }
        int ret = num[n];
        delete[] num;
        return ret;
    }
};
