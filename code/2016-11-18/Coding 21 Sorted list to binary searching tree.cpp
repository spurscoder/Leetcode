/*
问题描述：排序列表转换为二叉查找树
给出一个所有元素以升序排序的单链表，将它转换成一棵高度平衡的二分查找树

标签 ：
递归 链表

思路：.......注意循环；；；；；；；；；；；；

*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head == nullptr) return nullptr;
        int len = 0;
        ListNode *temp = head;
        while (temp) {
          temp = temp->next;
          len++;
        }
        if (len == 1)
          return new TreeNode(head->val);
        else if (len == 2) {
          TreeNode *root = new TreeNode(head->val);
          root->right = new TreeNode(head->next->val);
          return root;
        } else {
          len /= 2;
          temp = head;
          int cnt = 0;
          while (cnt < len)
          {
            temp = temp->next;
            cnt++;
          }
          ListNode* previous = head;
          while (previous->next != temp)
            previous = previous->next;
          previous->next = nullptr;
          TreeNode *root = new TreeNode(temp->val);
          root->left = sortedListToBST(head);
          root->right = sortedListToBST(temp->next);
          return root;
        }
    }
};
