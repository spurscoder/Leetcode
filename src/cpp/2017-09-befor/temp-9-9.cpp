#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* HEAD = new ListNode(-1);
		HEAD->next = head;
		head = HEAD;
		for (int i = 1; i < m; ++i)
			head = head->next;

		ListNode* newHead = NULL;
		ListNode* mov1 = head->next;
		ListNode* mov2 = head->next;
		for (int i = 0; i < n - m + 1; ++i) {
			ListNode* temp = mov1;
			mov1 = mov1->next;
			temp->next = newHead;
			newHead = temp;
		}
		head->next = newHead;
		mov2->next = mov1;

		return HEAD->next;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> node(numCourses, 0);
		vector<int> edge(prerequisites.size(), 0);
		for (int i = 0; i < prerequisites.size(); ++i)
			++node[prerequisites[i].first];

		bool flag = false;
		while (!flag) {
			flag = true;
			for (int i = 0; i < prerequisites.size(); ++i) {
				if (edge[i] == 0 && node[prerequisites[i].second] == 0) {
					edge[i] = 1;
					--node[prerequisites[i].first];
					flag = false;
				}
			}
		}

		for (int i = 0; i < prerequisites.size(); ++i)
			if (edge[i] == 0)
				return false;
		return true;
	}

	bool canFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> matrix(numCourses); // save this directed graph
		for (int i = 0; i < prerequisites.size(); ++i)
			matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

		vector<int> d(numCourses, 0); // in-degree
		for (int i = 0; i < numCourses; ++i)
			for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it)
				++d[*it];

		for (int j = 0; j < numCourses; ++j) {
			for (int i = 0; i < numCourses && d[i] != 0; ++i);

			if (i == numCourses)
				return false;

			d[i] = -1;
			for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it)
				--d[*it];

		}
		return true;
	}

	bool canFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> matrix(numCourses); // Save this directed graph
		for (int i = 0; i < prerequisites.size(); ++i)
			matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

		unordered_set<int> visited;
		vector<bool> flag(numCourses, false);
		for (int i = 0; i < numCourses; ++i)
			if (!flag[i])
				if (DFS(matrix, visited, i, flag))
					return false;
		return true;
	}

private:
	bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag) {
		flag[b] = true;
		visited.insert(b);
		for (auto it = matrix[b].begin(); it != matrix[b].end(); ++it)
			if (visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
				return true;
		visited.erase(b);
		return false;
	}
};


int main() {
	Solution A = Solution();

	vector<pair<int, int>> prerequisites{ {1,0}, {0, 1} };
	cout << A.canFinish(2, prerequisites) << endl;





	//ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);

	//ListNode* res = A.reverseBetween(head, 5, 5);

	//while (res) {
	//	cout << res->val << endl;
	//	res = res->next;
	//}

	return 0;
}