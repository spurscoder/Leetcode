#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem 1
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int N1 = nums1.size();
//	int N2 = nums2.size();
//	if (N1 > N2) return findMedianSortedArrays(nums2, nums1);
//	
//	int lo = 0, hi = N1, half_len = (N1 + N2 + 1) / 2;
//	while (lo <= hi) {
//		int mid1 = (lo + hi) / 2;
//		int mid2 = half_len - mid1;
//
//		if (mid1 < N1 && nums1[mid1] < nums2[mid2 - 1])
//			lo = mid1 + 1;
//		else if (mid1 > 0 && nums1[mid1 - 1] > nums2[mid2])
//			hi = mid1 - 1;
//		else {
//			int max_of_left, min_of_right;
//			if (mid1 == 0) max_of_left = nums2[mid2 - 1];
//			else if (mid2 == 0) max_of_left = nums1[mid1 - 1];
//			else max_of_left = max(nums1[mid1 - 1], nums2[mid2 - 1]);
//
//			if ((N1 + N2) % 2) return max_of_left;
//
//			if (mid1 == N1) min_of_right = nums2[mid2];
//			else if (mid2 == N2) min_of_right = nums1[mid1];
//			else min_of_right = min(nums1[mid1], nums2[mid2]);
//
//			return (max_of_left + min_of_right) / 2.0;
//		}
//	}
//}

int FindKth(vector<int>& nums1, int al, int ar, vector<int>& nums2, int bl, int br, int k) {
	if (al > ar) return nums2[bl + k - 1];
	if (bl > br) return nums1[al + k - 1];

	int amid = (al + ar) / 2;
	int bmid = (bl + br) / 2;

	if (nums1[amid] <= nums2[bmid]) {
		if (k <= (amid - al) + (bmid - bl) + 1)
			return FindKth(nums1, al, ar, nums2, bl, bmid - 1, k);
		else
			return FindKth(nums1, amid + 1, ar, nums2, bl, br, k - (amid - al) - 1);
	}
	else {
		if (k <= (amid - al) + (bmid - bl) + 1)
			return FindKth(nums1, al, amid - 1, nums2, bl, br, k);
		else
			return FindKth(nums1, al, ar, nums2, bmid + 1, br, k - (bmid - bl) - 1);
	}
}

// This is others solution
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int k = (n1 + n2 + 1) / 2;
	double v = (double)FindKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, k);

	if ((n1 + n1) % 2 == 0) {
		int k1 = k + 1;
		double v2 = (double)FindKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, k1);
		v = (v + v2) / 2;
	}
	return v;

}


// Problem 2
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	//ListNode *temp1 = head, *temp2 = head;
	//int len = 1;
	//while (temp1->next != NULL) {
	//	temp1 = temp1->next;
	//	++len;
	//}
	//if (len-- == n) return head->next;
	//while (len != n) {
	//	--len;
	//	temp2 = temp2->next;
	//}
	//temp2->next = temp2->next->next;
	//return head;

	// Solution 2
	ListNode *temp1 = head, *temp2 = head;
	for (int i = 0; i < n; ++i) {
		temp2 = temp2->next;
	}
	if (temp2 == NULL) return temp1->next;
	while (temp2->next != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = temp1->next->next;

	return head;
}

int removeElement1(vector<int>& nums, int val) {
	//int i = 0, j = nums.size()-1;
	//while (i <= j) {
	//	if (nums[i] == val && nums[j] != val) {
	//		nums[i] = nums[j];
	//		++i;
	//		--j;
	//	}
	//	if (nums[i] != val) ++i;
	//	if (nums[j] == val) --j;
	//}
	//return j + 1;

	// Improve
	int i = 0, j = nums.size() - 1;
	while (i <= j) {
		if (nums[i] == val) {
			nums[i] = nums[j];
			--j;
		}
		else
			++i;
	}
	return i;
}

ListNode* removeElements(ListNode* head, int val) {
	//ListNode* temp = NULL;
	//while (head != NULL && head->val == val) head = head->next;
	//if (head == NULL) return NULL;

	//temp = head;
	//while (temp->next != NULL) {
	//	if (temp->next->val == val)
	//		temp->next = temp->next->next;
	//	else
	//		temp = temp->next;
	//}
	//return head;

	//// Solution 2
	//if (head == NULL) return NULL;
	//head->next = removeElements(head->next, val);
	//return head->val == val ? head->next : head;

	// Solution 3 添加一个哨兵
	ListNode* temp = new ListNode(-1);
	temp->next = head;
	head = temp;

	while (head->next != NULL) {
		if (head->next->val == val)
			head->next = head->next->next;
		else
			head = head->next;
	}
	return temp->next;
}

// *********************************  分割线  **************************************************

int main() {

	ListNode* head = new ListNode(1);
	ListNode* temp = head;
	for (int i = 0; i < 6; ++i) {
		temp->next = new ListNode(i + 2);
		temp = temp->next;
	}
	temp->next = NULL;
	temp = head;
	
	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}

	cout << "------------";

	temp = removeElements(head, 7);

	while (temp != NULL) {
		cout << temp->val << endl;
		temp = temp->next;
	}


	//vector<int> nums1{ 1,5 };
	//vector<int> nums2{ 2,3,4,6 };
	//ListNode* head = new ListNode(1);
	//ListNode* temp = head;
	//for (int i = 0; i < 5; ++i) {
	//	temp->next = new ListNode(i + 2);
	//	temp = temp->next;
	//}
	//temp->next = NULL;

	//head = removeNthFromEnd(head, 6);

	//while (head != NULL) {
	//	cout << head->val << endl;
	//	head = head->next;
	//}

	// cout << findMedianSortedArrays(nums1, nums2) << endl;


	//vector<int> nums{ 3, 3,1,2,3, 3};
	//int len = removeElement(nums, 3);
	//cout << len << endl << endl;
	//for (int i = 0; i < len; ++i) {
	//	cout << nums[i] << endl;
	//}

	return 0;
}