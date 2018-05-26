#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set1(nums1.begin(), nums1.end());
		set<int> set2(nums2.begin(), nums2.end());

		vector<int> res;
		for (auto it : set1) {
			if (set2.find(it) != set2.end())
				res.push_back(it);
		}

		return res;
	}

	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		//unordered_map<int, int> map;
		//vector<int> res;
		//for (auto it : nums1) ++map[it];
		//for (auto it : nums2)
		//	if (map[it]-- > 0) res.push_back(it);
		//return res;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = nums1.size(), n2 = nums2.size();
		int i1 = 0, i2 = 0;
		vector<int> res;
		while (i1 < n1 && i2 < n2) {
			if (nums1[i1] == nums2[i2]) {
				res.push_back(nums1[i1]);
				++i1;
				++i2;
			}
			else if (nums1[i1] < nums2[i2])
				++i1;
			else
				++i2;
		}
		return res;

		//If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the intersections.

		//If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually(external sort), then read 2 elements from each array at a time in memory, record intersections.
	}

	vector<int> constructArray(int n, int k) {
		vector<int> res;
		for (int i = 1, j = n; i <= j; )
			res.push_back(k > 1 ? (k-- % 2 ? i++ : j--) : i++);
		return res;
	}

	bool isAdditiveNumber(string num) {
		//for (int i = 1; i <= num.size()/2; ++i) {
		//	for (int j = i + 1; j < num.size(); ++j) {
		//		string s1 = num.substr(0, i);
		//		string s2 = num.substr(i, j - i);
		//		if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) continue;
		//		long long d1 = atoll(s1.c_str()), d2 = atoll(s2.c_str());
		//		long long next = d1 + d2;
		//		string nexts = to_string(next);
		//		string now = s1 + s2 + nexts;
		//		while (now.size() < num.size()) {
		//			d1 = d2;
		//			d2 = next;
		//			next = d1 + d2;
		//			nexts = to_string(next);
		//			now += nexts;
		//		}
		//		if (now == num) return true;
		//	}
		//}
		//return false;

		for (int i = 1; i <= num.size() / 2; ++i)
			for (int j = 1; j <= (num.size()-i) / 2; ++j)
				if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
		return false;

	}
private:
	bool check(string num1, string num2, string num3) {
		if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') return false;
		string sum = add(num1, num2);
		if (sum == num3) return true;
		if (num3.size() <= sum.size() || sum.compare(num3.substr(0, sum.size())) != 0) return false;
		else return check(num2, sum, num3.substr(sum.size()));
	}

	string add(string num1, string num2) {
		string res;
		int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
		while (i >= 0 || j >= 0) {
			int sum = carry + (i >= 0 ? (num1[i--] - '0') : 0) + (j >= 0 ? (num2[j--] - '0') : 0);
			res.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		if (carry) res.push_back(carry + '0');
		reverse(res.begin(), res.end());
		return res;
	}


};

void show(int n, int k) {
	Solution A = Solution();
	vector<int> res = A.constructArray(n, k);
	for (auto it : res)
		cout << it << " ";
	cout << endl;
}

int main() {
	Solution A = Solution();

	show(5, 1);
	show(5, 2);
	show(5, 3);
	show(5, 4);
	show(5, 5);




	//vector<int> nums1{ 1,2,2,1 };
	//vector<int> nums2{ 0 };

	//vector<int> res = A.intersection(nums1, nums2);
	//for (auto it : res)
	//	cout << it << endl;



	return 0;
}