#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<pair<int, int>> temp(nums.size());
		for (int i = 0; i < nums.size(); ++i)
			temp[i] = make_pair(i, nums[i]);
		vector<int> res(nums.size(), 0);
		mergeSort(temp, res, 0, nums.size()-1);
		return res;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		else {
			if (root->val < p->val && root->val < q->val)
				return lowestCommonAncestor(root->right, p, q);
			else
				return root;
		}
	}

	bool isUgly(int num) {
		while (1) {
			if (num == 1)
				return true;
		
			if (num % 2 == 0)
				num /= 2;
			else if (num % 3 == 0)
				num /= 3;
			else if (num % 5 == 0)
				num /= 5;
			else
				return false;
		}
	}

	bool isHappy(int n) {
		unordered_set<int> temp;

		while (n != 1 && temp.find(n) == temp.end()) {
			temp.insert(n);
			int temp1 = 0;
			while (n) {
				temp1 += pow((n % 10), 2);
				n /= 10;
			}
			n = temp1;
			cout << " n: " << n << endl;
		}
		return n == 1 ? true : false;
	}

	int countPrimes(int n) {
		vector<bool> primes(n, true);
		int count = 0;
		for (int i = 2; i < n; ++i) {
			if (primes[i]) {
				++count;
				for (int j = 2; i*j < n; ++j)
					primes[i*j] = false;
			}
		}
		return count;
	}

	int nthUglyNumber(int n) {
		if (n <= 0) return false;
		if (n == 1) return true;
		vector<int> ugly(n);
		ugly[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < n; ++i) {
			ugly[i] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));
			if (ugly[i] == ugly[t2] * 2) ++t2;
			if (ugly[i] == ugly[t3] * 3) ++t3;
			if (ugly[i] == ugly[t5] * 5) ++t5;
		}
		return ugly[n - 1];
	}

	vector<int> twoSum1(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); ++i) {
			int numTofind = target - nums[i];
			if (hash.find(numTofind) != hash.end()) {
				return vector<int> {hash[numTofind], i};
			}
			hash[nums[i]] = i;
		}
	}

	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (numbers[i] + numbers[j] != target) {
			int sum = numbers[i] + numbers[j];
			if (sum < target) ++i;
			if (sum > target) --j;
		}
		return vector<int> {i + 1, j + 1};
	}

	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		if (target.find(k - root->val) != target.end()) return true;
		target.insert(root->val);
		if (findTarget(root->left, k) || findTarget(root->right, k)) return true;
		return false;
	}

	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> map;
		for (auto a : A)
			for (auto b : B)
				++map[a + b];
		int res = 0;
		for (auto c:C)
			for (auto d : D) {
				auto it = map.find(0 - c - d);
				if (it != map.end())
					res += it->second;
			}
		return res;
	}
private:
	unordered_set<int> target;
	void mergeSort(vector<pair<int, int>>& temp, vector<int>& res, int begin, int end) {
		if (begin >= end) return;
		int mid = (begin + end) / 2;
		mergeSort(temp, res, begin, mid);
		mergeSort(temp, res, mid + 1, end);

		merge(temp, res, begin, mid, end);
	}
	void merge(vector<pair<int, int>>& temp, vector<int>& res, int begin, int mid, int end) {
		int left = begin;
		int right = mid + 1;
		pair<int, int>* mer = new pair<int, int>[end - begin + 1];
		int index = 0;
		int count = 0;

		while (left <= mid && right <= end) {
			if (temp[left].second > temp[right].second) {
				++count;
				mer[index++] = temp[right ++];
			}
			else {
				mer[index++] = temp[left];
				res[temp[left++].first] += count;
			}
		}
		while (left <= mid) {
			mer[index++] = temp[left];
			res[temp[left++].first] += count;
		}
		while (right <= end) {
			mer[index++] = temp[right++];
		}
		while (begin <= end) {
			temp[end--] = mer[--index];
		}
	}
};


int main() {
	Solution A = Solution();

	vector<int> nums{ 2,7,11,15 };
	vector<int> res = A.twoSum(nums, 26);
	for (auto mem : res)
		cout << mem << endl;

	//for (int i = 1; i < 20; ++i) {
	//	cout << "i = " << i << " : " << A.nthUglyNumber(i) << endl;
	//}


	//cout << A.countPrimes(2) << endl;

	//cout << A.countPrimes(4) << endl;

	//cout << A.countPrimes(11) << endl;

	//cout << A.countPrimes(100) << endl;
	//cout << A.countPrimes(12) << endl;

	//cout << A.isHappy(7) << endl;

	//vector<int> nums{1,2};
	//vector<int> res = A.countSmaller(nums);
	//for (auto i : res)
	//	cout << i << " ";
	//cout << endl;

	return 0;
}