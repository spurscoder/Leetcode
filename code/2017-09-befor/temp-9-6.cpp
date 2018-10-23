#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int rob(vector<int>& nums) {
		//if (nums.empty()) return 0;
		//int len = nums.size();
		//vector<int> dp(len+1, 0);

		//for (int i = 0; i < len; ++i) {
		//	if (i > 1)
		//		dp[i+1] = max(dp[i - 1], dp[i - 2]) + nums[i];
		//	else
		//		dp[i+1] = nums[i];
		//}

		//return max(dp[len], dp[len - 1]);

		//int a = 0, b = 0;
		//for (int i = 0; i < nums.size(); ++i)
		//{
		//	if (i % 2) {
		//		b = max(b + nums[i], a);
		//	}
		//	else {
		//		a = max(a + nums[i], b);
		//	}
		//}
		//return max(a, b);

		int rob = 0, notrob = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int currob = notrob + nums[i];
			notrob = max(notrob, rob);
			rob = currob;
		}
		return max(rob, notrob);
	}

	ListNode* reverseList(ListNode* head) {
		//ListNode * reverse = NULL;
		//while (head) {
		//	ListNode *temp = head;
		//	head = head->next;
		//	temp->next = reverse;
		//	reverse = temp;
		//}
		//return reverse;

		return helper(head, NULL);
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {

	}
private:
	ListNode* helper(ListNode* head, ListNode* newhead) {
		if (head == NULL)
			return newhead;
		ListNode* next = head->next;
		head->next = newhead;
		return helper(next, head);
	}
};

class MinStack {
	//private:
	//	stack<int> s1;
	//	stack<int> s2;
	//public:
	//	MinStack() {
	//
	//	}
	//	void push(int x) {
	//		s1.push(x);
	//		if (s2.empty() || x <= s2.top()) s2.push(x);
	//	}
	//	void pop() {
	//		if (s1.top() == s2.top()) s2.pop();
	//		s1.pop();
	//	}
	//	int top() {
	//		return s1.top();
	//	}
	//	int getMin() {
	//		return s2.top();
	//	}

private:
	long min;
	stack<long> sta;
public:
	MinStack() {

	}
	void push(int x) {
		if (sta.empty()) {
			sta.push(0);
			min = x;
		}
		else {
			sta.push(x - min);
			if (x < min) min = x;
		}
	}
	void pop() {
		if (sta.empty()) return;
		long temp = sta.top();
		sta.pop();
		if (temp < 0) min = min - temp;
	}
	int top() {
		long temp = sta.top();
		return temp > 0 ? (int)(sta.top() + min) : (int)min;
	}
	int getMin() {
		return (int)min;
	}
};

int main() {
	Solution A = Solution();

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode* res = A.reverseBetween(head, 1, 2);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}

	//vector<int> nums{  };
	//cout << A.rob(nums) << endl;
	return 0;
}