/*问题描述
给定一个链表，旋转链表，使得每个节点向右移动k个位置，
其中k是一个非负数

样例
给出链表1->2->3->4->5->null和k=2
返回4->5->1->2->3->null
*/

/*思路1
先将链表进行连接，之后找到lines-k位置处，把链表剪开，there's ok;
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (head == NULL) return NULL;
        int lines = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
        	temp = temp->next;
        	lines++;
        }
        k %= lines;
        k = lines - k;
        temp->next = head;		//连接成功
        temp = head;
        while (--k)
        	temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};