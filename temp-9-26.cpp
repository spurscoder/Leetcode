#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> res(len, 1);
		for (int i = 1; i < len; ++i) {
			res[i] = nums[i - 1] * res[i - 1];
		}
		int temp = 1;
		for (int i = len - 1; i >= 0; --i) {
			res[i] = res[i] * temp;
			temp *= nums[i];
		}
		return res;
	}

	int findCircleNum(vector<vector<int>>& M) {
		vector<bool> visited(M.size(), true);
		int count = 0;
		for (int i = 0; i < M.size(); ++i) {
			if (visited[i]) {
				dfs(M, visited, i);
				++count;
			}
		}
	}

	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), cmp);
		for (int i = 0; i < people.size(); ++i) {
			cout << people[i].first << "  " << people[i].second << endl;
		}
		vector<pair<int, int>> res;
		return res;
	}

private:
	void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
		for (int j = 0; j < M.size(); ++j) {
			if (M[i][j] == 1 && visited[j]) {
				visited[j] = false;
				dfs(M, visited, j);
			}
		}
	}

	static bool cmp(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.first == b.first)
			return a.second  < b.second;
		return a.first > b.first;
	}

};


int main() {
	Solution A = Solution();

	vector<pair<int, int>> people{ {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
	A.reconstructQueue(people);


	//vector<int> nums{ 1,2 };
	//vector<int> res = A.productExceptSelf(nums);
	//for (int i = 0; i < res.size(); ++i) {
	//	cout << res[i] << endl;
	//}



	return 0;
}