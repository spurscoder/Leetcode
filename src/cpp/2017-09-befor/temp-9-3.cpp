#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:

	int singleNumber1(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			res ^= nums[i];
		}
		return res;
	}

	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			int num = 0;
			for (int j = 0; j < nums.size(); ++j) {
				if ((nums[j] >> i) & 1 == 1) {
					num++;
					num %= 3;
				}
			}
			if (num)
				res |= (num << i);
		}
		return res;
	}
	//vector<int> singleNumber(vector<int>& nums) {
	//	int temp = 0;
	//	for (auto num : nums) temp ^= num;
	//	int last = (temp & (temp - 1)) ^ temp;
	//	int A = 0, B = 0;
	//	for (auto num : nums) {
	//		if (num & temp)
	//			A ^= num;
	//		else
	//			B ^= num;
	//	}
	//	return vector<int>{A, B};
	//}

	int minssingNumber(vector<int>& nums) {
		//long temp1 = 0, temp2 = (nums.size()+1)*nums.size() / 2 ;
		//for (int i = 0; i < nums.size(); ++i) {
		//	temp1 += nums[i];
		//}
		//return temp2 - temp1;

		// Others Solution
		int res = 0, i = 0;
		for (int i = 0; i < nums.size(); ++i) {
			res = res ^ i ^ nums[i];
		}
		return res ^ i;
	}

	bool hasCycle(ListNode * head) {
		if (!head || !head->next) return false;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (slow != fast && fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (slow == fast)
			return true;
		else
			return false;
	}

	ListNode* detectCycle(ListNode* head) {
		if (!head || !head->next) return NULL;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (slow != fast && fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (slow == fast) {
			slow = head;
			fast = fast->next;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
		return NULL;
	}


};

int main() {

	Solution A = Solution();

	ListNode* head = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* fouth = new ListNode(4);
	head->next = second;
	second->next = third;
	third->next = fouth;
	fouth->next = head;

	ListNode* res = A.detectCycle(head);
	if (res != NULL)
		cout << res->val << endl;



	//vector<int> nums{ 1,1,1,3 };
	//
	//cout << A.singleNumber(nums) << endl;

}