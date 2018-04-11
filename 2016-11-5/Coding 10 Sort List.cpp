/*问题描述：
在 O(n log n) 时间复杂度和常数级的空间复杂度下给链表排序。

当参数只有一个时候，可以采用快慢指针来解决寻找中间点的问题。

*/
/*思路：
分别用归并排序和快速排序做一遍
*/

// ---------------------------------------归并排序
/*
++++++++设置快慢指针，快指针走两个节点，慢指针走一个节点
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
 */
 class Solution {
 public:
     /**
      * @param head: The first node of linked list.
      * @return: You should return the head of the sorted linked list,
                     using constant space complexity.
      */
     ListNode *sortList(ListNode *head) {
         // write your code here
         if (head == NULL || head->next == NULL)
             return head;
         ListNode* Fast = head->next;
         ListNode* Slow = head;
         // 寻找快慢指针
         while (Fast != NULL && Fast->next != NULL) {
           Fast = Fast->next->next;
           Slow = Slow->next;
         }
         // 分割链表
         Fast = Slow;
         Slow = Slow->next;
         Fast->next = NULL;
         head = sortList(head);
         Slow = sortList(Slow);
         head = merge(head, Slow);
         Fast = Slow = NULL;
         return head;
     }
 private:
     /**
      *
      */
     ListNode *merge(ListNode* head1, ListNode* head2) {
       if (head1 == NULL || head2 == NULL)
           return head1 == NULL ? head2 : head1;
       // 返回的链表头
       ListNode* head = NULL;
       if (head1->val > head2->val) {
         head = head2;
         head2 = head2->next;
       } else {
         head = head1;
         head1 = head1->next;
       }
       ListNode* temp = head;
       while (head1 != NULL && head2 != NULL) {
         if (head1->val > head2->val) {
           temp->next = head2;
           head2 = head2->next;
         } else {
           temp->next = head1;
           head1 = head1->next;
         }
         temp = temp->next;
       }
       if (head1 == NULL) {
         temp->next = head2;
       } else {
         temp->next = head1;
       }
       return head;
     }
 };



//---------------------------------------------快速排序11111
/*
只改变链接的指向。
将比基元小的值，链接到做链表中；比基元大的值，链接到右链表中
*/
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
          return head;
        ListNode headPrev(0, head);
        sortList(&headPrev, head, NULL);
        return headPrev.next;
    }
private:
    void sortList(ListNode* pHeadPrev, ListNode* pHead, ListNode* pTail) {
      if (pHead == pTail || pHead->next == pTail)
        return;
      ListNode* pMid = Partation(pHeadPrev, pHead, pTail);
      sortList(pHeadPrev, pHeadPrev->next, pMid);
      sortList(pMid, pMid->next, pTail);
    }
    ListNode* Partation(ListNode* pHeadPrev, ListNode* pHead, ListNode* pTail) {
      int key = pHead->val;
      ListNode nodeL(0), nodeR(0);
      ListNode* pLeftPrev = &nodeL;
      ListNode* pRightPrev = &nodeR;
      for (ListNode* pNode = pHead->next; pNode != pTail; pNode = pNode->next) {
        if (pNode->val < key) {
          pLeftPrev->next = pNode;
          pLeftPrev = pNode;
        } else {
          pRightPrev->next = pNode;
          pRightPrev = pNode;
        }
      }
      pRightPrev->next = pTail;
      pLeftPrev->next = pHead;
      pHead->next = nodeR.next;
      pHeadPrev->next = nodeL.next;
      return pHead;
    }
};



//-----------------------------------快速排序2222222222
//--------------------------只改变链表的值
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
          return head;
        sortList(head, NULL);
        return head;
    }
    void sortList(ListNode *pHead, ListNode *pTail) {
      if (pHead == pTail || pHead->next == pTail)
        return;
      ListNode* pMid = Partation(pHead, pTail);
      sortList(pHead, pMid);
      sortList(pMid->next, pTail);
    }
    ListNode* Partation(ListNode* pHead, ListNode* pTail) {
      if (pHead == pTail || pHead->next == pTail)
        return pHead;
      ListNode* pPivot = pHead;
      int key = pHead->val;
      for (ListNode* pNode = pHead->next; pNode != pTail; pNode = pNode->next) {
        if (pNode->val < key) {
          pPivot = pPivot->next;
          swap(pNode, pPivot);
        }
      }
      swap(pHead, pPivot);
      return pPivot;
    }
    void swap(ListNode* pA,ListNode* pB) {
      int temp = pA->val;
      pA->val = pB->val;
      pB->val = temp;
    }
};
