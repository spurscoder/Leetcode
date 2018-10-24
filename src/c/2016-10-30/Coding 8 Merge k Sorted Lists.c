/*问题描述
合并k个排序链表，
并且返回合并后的排序链表。
尝试分析和描述其复杂度。
*/

/*思路1 
简单的分治法。先分支，后合并
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
 /*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        return partition(lists, 0, lists.size() - 1);
    }

    ListNode* partition(vector<ListNode*>& lists, int start, int end) {
        if(start == end) {
            return lists[start];
        }

        if(start < end) {
            int mid = (start + end) / 2;
            ListNode* l1 = partition(lists, start, mid);
            ListNode* l2 = partition(lists, mid + 1, end);
            return mergeTwoLists(l1, l2);
        }
        return NULL;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == NULL) return l1;
        if(l1 == NULL) return l2;

        if(l1->val > l2->val) {
            ListNode* temp = l2;
            temp->next = mergeTwoLists(l1, l2->next);
            return temp;
        } else {
            ListNode* temp = l1;
            temp->next = mergeTwoLists(l1->next, l2);
            return temp;
        }
    }
};
*/


/*思路二------------------------------------------------------------------
改进的分治法。即
将数组分段先以2个为一组，遍历排序；之后以4个为一组，遍历排序；
以此类推。逐步排序。
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        int size = lists.size();
        if(size == 0) return NULL;
        if(size == 1) return lists[0];

        int i = 2, j;
        while(i / 2 < size) {
            for(j = 0; j < size; j += i) {
                ListNode* p = lists[j];
                if(j + i / 2 < size) {
                    p = mergeTwoLists(p, lists[j + i / 2]);
                    lists[j] = p;
                }
            }
            i *= 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == NULL) return l1;
        if(l1 == NULL) return l2;

        if(l1->val > l2->val) {
            ListNode* temp = l2;
            temp->next = mergeTwoLists(l1, l2->next);
            return temp;
        } else {
            ListNode* temp = l1;
            temp->next = mergeTwoLists(l1->next, l2);
            return temp;
        }
    }
};

