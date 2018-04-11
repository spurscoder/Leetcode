/*问题描述
翻转链表中第m个节点到第n个节点的部分
注意事项
m，n满足1 ≤ m ≤ n ≤ 链表长
样例
给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null
*/

//挑战：在原地一次翻转完成

/*思路：
*/

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
     ListNode *reverseBetween(ListNode *head, int m, int n) {
         // write your code here
         if (m == n || head == NULL || head->next == NULL)
           return head;
         int num = 0;
         ListNode* temp = head;
         int *A = new int[n - m + 1];
         int i = 0;
         while (temp != NULL) {
           num++;
           if (m <= num && num <= n) {
             A[i] = temp->val;
             i++;
           }
           temp = temp->next;
         }
         temp = head;
         num = 0;
         while (temp != NULL) {
           num++;
           if (m <= num && num <= n) {
             i--;
             temp->val = A[i];
           }
           temp = temp->next;
         }
         return head;
     }
 };




//注意动态申请数组    int *A = new int [10];
