#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;



class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		/*vector<int> res;
		vector<int> temp(k, 0);
		for (int i = 0; i < k; ++i)
			temp[i] = nums[i];
		for (int i = k; i < nums.size(); ++i) {
			int max = *max_element(temp.begin(), temp.end());
			res.push_back(max);
			temp[i%k] = nums[i];
		}
		res.push_back(*max_element(temp.begin(), temp.end()));

		return res;*/

		deque<int> dq;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) res.push_back(nums[dq.front()]);
		}
		return res;
	}
	// ================================= Solution 1 O(NLOGK)
	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		vector<int> res;
		if (k == 0) return res;
		multiset<int> w;
		for (int i = 0, n = (int)nums.size(); i < n; ++i) {
			if (i >= k)
				w.erase(w.find(nums[i - k]));
			w.insert(nums[i]);
			if (i >= k - 1)
				res.push_back(*w.rbegin());
		}
		return res;
	}

	// ================================== Solution 2 O(NLOGN)
	vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
		vector<int> res;
		if (k == 0) return res;
		priority_queue<pair<int, int>> w;
		for (int i = 0, n = (int)nums.size(); i < n; ++i) {
			while (!w.empty() && w.top().second <= i - k)
				w.pop();
			w.push(make_pair(nums[i], i));
			if (i >= k - 1)
				res.push_back(w.top().first);
		}
		return res;
	}

	// ================================= Solution 3 O(N)
	vector<int> maxSildingWindow3(vector<int>& nums, int k) {
		vector<int> res;
		if (k == 0) return res;
		deque<int> w;
		for (int i = 0, n = (int)nums.size(); i < n; ++i) {
			while (!w.empty() && w.front() <= i - k)
				w.pop_front();
			while (!w.empty() && nums[w.back()] <= nums[i])
				w.pop_back();
			w.push_back(i);
			if (i >= k - 1)
				res.push_back(nums[w.front()]);
		}
		return res;
	}


	int maxProfit(vector<int>& prices) {

	}


	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		//vector<unordered_set<int>> matrix(n);
		//for (int i = 0; i < edges.size(); ++i) {
		//	matrix[edges[i].first].insert(edges[i].second);
		//	matrix[edges[i].second].insert(edges[i].first);
		//}
		//vector<int> ingree(n, 0);
		//for (int i = 0; i < n; ++i) ingree[i] = matrix[i].size();
		//while (1) {
		//	vector<int> temp;
		//	int num = 0;
		//	for (int i = 0; i < n; ++i) {
		//		if (ingree[i] == 1) {
		//			temp.push_back(i);
		//			ingree[i] = 0;
		//		}
		//		if (ingree[i] > 1)
		//			++num;
		//	}

		//	if (num <= 2)
		//		break;
		//		
		//	for (int i = 0; i < temp.size(); ++i)
		//		for (auto it = matrix[temp[i]].begin(); it != matrix[temp[i]].end(); ++it)
		//			--ingree[*it];
		//}
		//vector<int> res;
		//for (int i = 0; i < n; ++i)
		//	if (ingree[i] >= 2)
		//		res.push_back(i);

		//return res;

		vector<unordered_set<int>> graph(n);
		for (auto e : edges) {
			graph[e.first].insert(e.second);
			graph[e.second].insert(e.first);
		}
		vector<int> degree(n, 0); // degree
		for (int i = 0; i < n; ++i) degree[i] = graph[i].size();
		for (int remain = n, j; remain > 2;) {
			vector<int> del;
			for (j = 0; j < n; ++j) {
				if (degree[j] == 1) {
					remain--;
					del.push_back(j);
					degree[j] = -1;
				}
			}
			for (auto k : del)
				for (auto neigh : graph[k]) --degree[neigh];
		}
		vector<int> res;
		for (int i = 0; i < n; ++i) if (degree[i] >= 0) res.push_back(i);
		return res;
	}


};


// ========================= ·Ö¸îÏß =========================

int main() {
	Solution A = Solution();

	vector<pair<int, int>> edges{ {0,3}, {1,3}, {2,3}, {4,3}, {5,4} };
	vector<pair<int, int>> edges1{ {1,0}, {1,2}, {1,3} };
	vector<int> res = A.findMinHeightTrees(6, edges);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;


	//vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
	//vector<int> res = A.maxSlidingWindow(nums, 3);
	//for (int i = 0; i < res.size(); ++i)
	//	cout << res[i] << endl;
	return 0;
}