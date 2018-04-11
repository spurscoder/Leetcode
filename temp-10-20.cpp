#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <numeric>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		//int len = nums.size();
		//k = k%len;
		//if (k > len / 2) {
		//	k = len - k;
		//	vector<int> temp(k, 0);
		//	for (int i = 0; i < k; ++i)
		//		temp[i] = nums[i];
		//	for (int i = k; i < len; ++i)
		//		nums[i - k] = nums[i];
		//	for (int i = 0; i < k; ++i)
		//		nums[len - k + i] = temp[i];
		//}
		//else {
		//	vector<int> temp(k, 0);
		//	for (int i = 0; i < k; ++i)
		//		temp[i] = nums[len - k + i];
		//	for (int i = len - 1; i >= k; --i)
		//		nums[i] = nums[i - k];
		//	for (int i = 0; i < k; ++i)
		//		nums[i] = temp[i];
		//}


		//int len = nums.size();
		//k = k%len;

		//reverse(nums.begin(), nums.end());
		//reverse(nums.begin(), nums.begin() + k);
		//reverse(nums.begin()+k, nums.end());

		int len = nums.size();
		int pos = 0;
		for (; k = k%len; len -= k, pos += k) {
			for (int i = 0; i < k; ++i)
				swap(nums[pos + i],nums[len - k + pos + i]);
		}
	}

	void rotate(int nums[], int n, int k) {
		for (; k %= n; n -= k)
			for (int i = 0; i < k; ++i) {
				swap(*nums, nums[n - k]);
				nums++;
			}
	}

	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		int len = 1;
		ListNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
			++len;
		}
		temp->next = head;

		k = k % len;
		k = len - k;
		while (--k)
			head = head->next;
		temp = head->next;
		head->next = NULL;
		return temp;
	}

	bool isAdditiveNumber(string num) {

	}

	int firstUniqChar(string s) {
		//vector<int> Char(26, 0);
		//for (int i = 0; i < s.length(); ++i)
		//	++Char[s[i] - 'a'];
		//for (int i = 0; i < s.length(); ++i)
		//	if (Char[s[i] - 'a'] == 1)
		//		return i;
		//return -1;

		unordered_map<char, int> m;
		for (auto &c : s)
			++m[c];
		for (int i = 0; i < s.length(); ++i)
			if (m[s[i]] == 1) return i;
		return -1;
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		int iter = 31;
		while (iter--) {
			if (n & 1)
				res ^= 1;
			n >>= 1;
			res <<= 1;
		}
		if (n & 1)
			res ^= 1;
		return res;
	}

	bool checkPossibility(vector<int>& nums) {
		//if (nums.size() == 0) return true;
		//int stage = 0;
		//for (int i = 0; i < nums.size() - 1; ++i) {
		//	if (nums[i] > nums[i + 1]) {
		//		if (stage == 0) {
		//			if ((i == 0) || (i == nums.size()-2) || (nums[i - 1] <= nums[i + 1] && nums[i+1] <= nums[i+2]) || (nums[i-1] <= nums[i] && nums[i] <= nums[i+2]) )
		//				stage = 1;
		//			else
		//				return false;
		//		}
		//		else
		//			return false;
		//	}
		//}
		//return true;

		int cnt = 0;
		for (int i = 1; i < nums.size() && cnt <= 1; ++i) {
			if (nums[i - 1] > nums[i]) {
				cnt++;
				if (i - 2 < 0 || nums[i - 2] <= nums[i]) nums[i - 1] = nums[i];
				else nums[i] = nums[i - 1];
			}
		}
		return cnt <= 1;
	}
private:


};

int main() {
	Solution A = Solution();

	vector<int> nums{ 4,2,3 };
	vector<int> nums1{ 4,2,1 };
	vector<int> nums2{ 1,4,2,3 };
	vector<int> nums3{};
	vector<int> nums4{ 1,2,3,4 };
	vector<int> nums5{ 1,4,2,3,2 };
	vector<int> nums6{ 2,3,3,2,4 };
	vector<int> nums7{ 2,3 };
	vector<int> nums8{ 3,2 };
	vector<int> nums9{ 2,3,4 };
	vector<int> nums10{ 2,4,2 };
	
	cout << A.checkPossibility(nums) << endl;
	cout << A.checkPossibility(nums1) << endl;
	cout << A.checkPossibility(nums2) << endl;
	cout << A.checkPossibility(nums3) << endl;
	cout << A.checkPossibility(nums4) << endl;
	cout << A.checkPossibility(nums5) << endl;
	cout << A.checkPossibility(nums6) << endl;
	cout << A.checkPossibility(nums7) << endl;
	cout << A.checkPossibility(nums8) << endl;
	cout << A.checkPossibility(nums9) << endl;
	cout << A.checkPossibility(nums10) << endl;



	//uint32_t n = 43261596;
	//cout << A.reverseBits(1) << endl;


	//string s = "leetcode";
	//string s1 = "loveleetcode";
	//string s2 = "";
	//string s3 = "qqwwqw";

	//cout << A.firstUniqChar(s) << endl;
	//cout << A.firstUniqChar(s1) << endl;
	//cout << A.firstUniqChar(s2) << endl;
	//cout << A.firstUniqChar(s3) << endl;



	//ListNode* head = new ListNode(1);
	////ListNode* temp = head;
	////for (int i = 2; i < 7; ++i) {
	////	temp->next = new ListNode(i);
	////	temp = temp->next;
	////}
	//ListNode* res = A.rotateRight(head, 2);
	//while (res != NULL) {
	//	cout << res->val << endl;
	//	res = res->next;
	//}


	//vector<int> nums{ 1,2,3,4,5,6,7 };
	//int nums2[] = {1,2,3,4,5,6,7};
	//A.rotate(nums2, 7, 2);
	//for (int i = 0; i < 7; ++i)
	//	cout << nums2[i] << endl;
	////A.rotate(nums1, 11939);
	//cout << "--------------" << endl;
	//for (auto num : nums)
	//	cout << num << endl;




	return 0;
}