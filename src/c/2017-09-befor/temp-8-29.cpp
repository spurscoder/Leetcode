#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//bool isMatch(string s, string p) {
	//	if (p.empty()) return s.empty();
	//	if (p[1] == '*')
	//		return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)));
	//	else
	//		return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	//}

	//bool isMatch(string s, string p) {
	//	int m = s.size(), n = p.size();
	//	vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
	//	
	//	f[0][0] = true;
	//	for (int i = 1; i <= m; ++i)
	//		f[i][0] = false;
	//	for (int j = 1; j <= n; ++j)
	//		f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
	//	for (int i = 1; i <= m; ++i)
	//		for (int j = 1; j <= n; ++j)
	//			if (p[j - 1] != '*')
	//				f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
	//			else
	//				f[i][j] = f[i][j - 1] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
	//	return f[m][n];
	//}

	//bool isMatch(string s, string p) {
	//	int m = s.length(), n = p.length();
	//	vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
	//	dp[0][0] = true;
	//	for (int i = 0; i <= m; i++)
	//		for (int j = 1; j <= n; j++)
	//			if (p[j - 1] == '*')
	//				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
	//			else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
	//	return dp[m][n];
	//}

	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (p[j - 1] != '*')
					dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				else
					dp[i][j] = dp[i][j - 2] || ( i > 0 && ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]));
		return dp[m][n];
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0), *temp = head;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				temp->next = l1;
				l1 = l1->next;
				temp = temp->next;
			}
			else {
				temp->next = l2;
				l2 = l2->next;
				temp = temp->next;
			}
		}
		if (l1 == NULL) temp->next = l2;
		else temp->next = l1;

		return head->next;
	}

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] <= nums2[j])
				nums1[k--] = nums2[j--];
			else
				nums1[k--] = nums1[i--];
		}
		if (i == -1)
			for (int i = j; i >= 0; --i)
				nums1[k--] = nums2[i];
	}

	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* d = new ListNode(0);
		ListNode* e = d;
		while (head1 || head2) {
			if (head1 && (!head2 || head1->val <= head2->val)) {
				e = e->next = head1;
				head1 = head1->next;
			}
			if (head2 && (!head1 || head2->val < head1->val)) {
				e = e->next = head2;
				head2 = head2->next;
			}
		}
		e->next = NULL;
		return d->next;
	}

	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* headb = slow->next;
		slow->next = NULL;
		return merge(sortList(head), sortList(headb));
	}
};






// ******************************* ·Ö¸îÏß **********************************

int main() {
	Solution A = Solution();

	vector<int> nums1{ 11,13,15,17,0,0,0,0,0 };
	vector<int> nums2{ 2,4,6,8 };
	A.merge(nums1, 4, nums2, 4);
	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << endl;




	//cout << A.isMatch("aa", "a") << endl;
	//cout << A.isMatch("aa", "aa") << endl;
	//cout << A.isMatch("aaa", "aa") << endl;
	//cout << A.isMatch("aa", "a*") << endl;
	//cout << A.isMatch("aa", ".*") << endl;
	//cout << A.isMatch("ab", ".*") << endl;
	//cout << A.isMatch("aab", "c*a*b") << endl;
	//cout << A.isMatch("a", "a*") << endl;
	//cout << A.isMatch("aaa", "a*a") << endl;
	return 0;
}