#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		int sum = 0;
		for (auto num : nums) {
			++map[num];
			sum += num;
		}
		if (sum % k != 0) return false;
		int part = sum / k;
		for (auto num : nums) {
			if (num > sum / k) return false;
			--map[num];
			if (map[num] < 0) return false;
			--map[part - num];
			if (map[part - num] < 0) return false;
		}

		return true;
	}

	int compress(vector<char>& chars) {
		if (chars.size() <= 1) return chars.size();
		int index = 0, cur = 1;
		char c = chars[0];
		for (int i = 0; i < chars.size(); ++i) {
			if (i == chars.size() - 1 || chars[i] != chars[i + 1]) {
				chars[index++] = c;
				if (i != chars.size() - 1) c = chars[i + 1];
				if (cur != 1) {
					string s = to_string(cur);
					for (auto c : s) chars[index++] = c;
				}
				cur = 1;
			}
			else
				++cur;
		}
		return index;
	}

	int findContentChildren(vector<int>& g, vector<int>& s) {
		if (!g.size() || !s.size()) return 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int i = g.size() - 1, j = s.size() - 1;
		int res = 0;
		while (i >= 0 && j >= 0) {
			if (g[i] <= s[j]) {
				--i; --j; ++res;
			}
			else
				--i;
		}
		return res;
	}

	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> map;
		for (auto s : words) ++map[s];
		vector<pair<string, int>> temp;
		for (auto it = map.begin(); it != map.end(); ++it) temp.push_back(make_pair(it->first, it->second));
		sort(temp.begin(), temp.end(), [](pair<string,int>& a, pair<string, int>& b) {return a.second == b.second ? a.first < b.first : a.second > b.second; });
		vector<string> res;
		for (auto it = temp.begin(); k-- > 0; ++it) {
			res.push_back(it->first);
		}
		return res;
	}

private:


};

int main() {
	Solution A = Solution();

	vector<string> words{ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	vector<string> res =  A.topKFrequent(words, 4) ;
	for (auto it : res)
		cout << it << " ";
	cout << endl;

	//vector<int> g{ 1,2,3 };
	//vector<int> s{ 1,1 };
	//vector<int> g1{ 1,2 };
	//vector<int> s1{ 1,2,3 };
	//cout << A.findContentChildren(g, s) << endl;
	//cout << A.findContentChildren(g1, s1) << endl;


	//vector<char> chars{ 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
	//vector<char> chars1{ 'a' };
	//vector<char> chars2{ 'a','a','b','b','c','c','c','d' };
	//int res1 = A.compress(chars);
	//for (int i = 0; i < res1; ++i)
	//	cout << chars[i] << " ";
	//cout << '\n' << res1 << endl;
	//int res2 = A.compress(chars1);
	//for (int i = 0; i < res2; ++i)
	//	cout << chars1[i] << " ";
	//cout << '\n' << res2 << endl;
	//int res3 = A.compress(chars2);
	//for (int i = 0; i < res3; ++i)
	//	cout << chars2[i] << " ";
	//cout << '\n' << res3 << endl;




	//vector<int> nums{ 2,2,2,2,3,4,5 };
	//cout << A.canPartitionKSubsets(nums, 4) << endl;
	//cout << A.canPartitionKSubsets(nums, 5) << endl;
	return 0;
}