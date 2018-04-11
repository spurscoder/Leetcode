#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	void sortColors(vector<int>& nums) {
		//for (int i = 0; i < nums.size(); ++i)
		//	for (int j = 0; j < nums.size() - i - 1; ++j) {
		//		if (nums[j] > nums[j+1]) {
		//			int temp = nums[j+1];
		//			nums[j+1] = nums[j];
		//			nums[j] = temp;
		//		}
		//	}
		//
		// Insert Sort
		//for (int i = 1; i < nums.size(); ++i) {
		//	int j = i - 1;
		//	int temp = nums[i];
		//	for (; j >= 0; --j) {
		//		
		//		if (temp < nums[j]) {
		//			nums[j+1] = nums[j];
		//		}
		//		else
		//			break;
		//	}
		//	nums[j + 1] = temp;
		//}
		//
		//int right = nums.size()-1, left = 0;
		//for (int i = 0; i <= right; ++i) {
		//	while (nums[i] == 2 && i < right) swap(nums[i], nums[right--]);
		//	while (nums[i] == 0 && i > left) swap(nums[i], nums[left++]);
		//}
		//
		int num0 = 0, num1 = 0, num2 = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) num0++;
			else if (nums[i] == 1) num1++;
			else num2++;
		}
		for (int i = 0; i < num0; ++i) nums[i] = 0;
		for (int i = 0; i < num1; ++i) nums[i + num0] = 1;
		for (int i = 0; i < num2; ++i) nums[i + num0 + num1] = 2;
	}

	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *res = new ListNode(INT_MIN), *temp = NULL;

		while (head) {
			temp = head;
			head = head->next;
			temp->next = NULL;
			ListNode* temp_head = res;
			
			while (temp_head->next) {
				if (temp_head->next->val > temp->val)
					break;
				temp_head = temp_head->next;
			}
			temp->next = temp_head->next;
			temp_head->next = temp;
		}
		return res->next;
	}

	//ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	//	set<ListNode*> temp;
	//	while (headA) {
	//		temp.insert(headA);
	//		headA = headA->next;
	//	}
	//	while (headB) {
	//		if (temp.find(headB) != temp.end())
	//			return headB;
	//		headB = headB->next;
	//	}
	//	return NULL;
	//}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//ListNode* p1 = headA;
		//ListNode* p2 = headB;

		//if (!p1 || !p2) return NULL;
		//while (p1 && p2 && p1 != p2) {
		//	p1 = p1->next;
		//	p2 = p2->next;

		//	if (p1 == p2) return p1;

		//	if (!p1) p1 = headB;
		//	if (!p2) p2 = headA;
		//}

		// Solution concise
		ListNode *cur1 = headA, *cur2 = headB;
		while (cur1 != cur2) {
			cur1 = cur1 ? cur1->next : headB;
			cur2 = cur2 ? cur2->next : headA;
		}
		return cur1;	
	}

	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> temp(list1.size());
		for (int i = 0; i < list1.size(); ++i) {
			temp[list1[i]] = i;
		}
		int res = INT_MAX;
		vector<string> ress;
		for (int i = 0; i < list2.size(); ++i)
			if (temp.find(list2[i]) != temp.end())
				if (temp[list2[i]] + i < res) {
					res = temp[list2[i]] + i;
					ress.clear();
					ress.push_back(list2[i]);
				}
				else {
					if (temp[list2[i]] + i == res)
						ress.push_back(list2[i]);
				}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		if (lists.size() == 1) return lists[0];
		ListNode* head = new ListNode(-1), *temp = head;
		while (true) {
			int cur = INT_MAX;
			int pos = -1;
			for (int i = 0; i < lists.size(); ++i) {
				if (lists[i] && cur > lists[i]->val) {
					cur = lists[i]->val;
					pos = i;
				}
			}

			if (cur == INT_MAX)
				return head->next;

			temp->next = lists[pos];
			lists[pos] = lists[pos]->next;
			temp = temp->next;
		}
	}
};



// ******************************** ·Ö¸îÏß ***********************************

int main() {

	ListNode* head = new ListNode(2), *temp = head;
	temp->next = new ListNode(1);
	temp = temp->next;
	temp->next = new ListNode(3);
	//for (int i = 0; i < 6; ++i) {
	//	temp->next = new ListNode(i);
	//	temp = temp->next;
	//}
	Solution A = Solution();
	ListNode* head1 = A.insertionSortList(head);

	while (head1) {
		cout << head1->val << endl;
		head1 = head1->next;
	}


	//vector<int> nums{ 2,2,1,2,1,2,1,0,0,1,0 };
	//Solution A = Solution();
	//A.sortColors(nums);
	//for (int i = 0; i < nums.size(); ++i)
	//	cout << nums[i] << " ++ ";
	//cout << endl;

	return 0;
}