#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) :label(x) {};
};

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty()) return 0;
		int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
		for (int l = 0; l < col; ++l) {
			vector<int> sums(row, 0);
			for (int r = l; r < col; ++r) {
				for (int i = 0; i < row; ++i)
					sums[i] += matrix[i][r];

				set<int> acusum;
				acusum.insert(0);
				int sum = 0, cur = INT_MIN;
				for (int i = 0; i < row; ++i) {
					sum += sums[i];
					auto it = acusum.lower_bound(sum - k);
					if (it != acusum.end()) cur = max(cur, sum - *it);
					acusum.insert(sum);
				}
				res = max(res, cur);
			}
		}
		return res;
	}
	
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
		if (!node) return NULL;
		if (map.find(node) == map.end()) {
			map[node] = new UndirectedGraphNode(node->label);
			for (auto it : node->neighbors)
				map[node]->neighbors.push_back(cloneGraph(it));
		}
		return map[node];
	}

	UndirectedGraphNode* cloneGraphBFS(UndirectedGraphNode* node) {
		if (!node) return NULL;
		map[node] = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> que;
		que.push(node);
		while (!que.empty()) {
			auto cur = que.front();
			que.pop();
			for (auto it : cur->neighbors) {
				if (map.find(it) == map.end()) {
					map[it] = new UndirectedGraphNode(it->label);
					que.push(it);
				}
				map[cur]->neighbors.push_back(map[it]);
			}
		}
		return map[node];
	}

	string solveEquation(string equation) {
		int i = 0;
		// left
		int left_x = 0, left_coef = 0;
		for (; i < equation.length(); ++i) {
			if (equation[i] == '=') break;
			switch (equation[i]) {
			case 'x':
				if (i == 0) left_x = 1;
				int j = i - 1;
				for (; j >= 0; --j) {
					if (equation[j] == '-' || equation[j] == '+')
				}
			case '+':
			case '-':
			default:

			}
		}

		// right;
	}

private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;


};

set<UndirectedGraphNode*> node1;
void show(UndirectedGraphNode * node) {
	if (!node) return;
	if (node1.find(node) == node1.end()) {
		cout << node->label << endl;
		node1.insert(node);
		for (auto it : node->neighbors) {
			show(it);
		}
	}
}

int main() {
	Solution A = Solution();

	UndirectedGraphNode* node = new UndirectedGraphNode(0);
	UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
	node->neighbors.push_back(node1);
	node->neighbors.push_back(node2);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node2);

	UndirectedGraphNode* res = A.cloneGraph(node);


	show(res);

	//cout << res->label << " -> " << 0 << endl;
	//cout << res->neighbors[0]->label << " -> " << 1 << endl;
	//cout << res->neighbors[1]->label << " -> " << 2 << endl;
	//cout << res->neighbors[0]->neighbors[0]->label << " -> " << 2 << endl;
	//cout << res->neighbors[1]->neighbors[0]->label << " -> " << 2 << endl;

	//UndirectedGraphNode* root = new UndirectedGraphNode(1);
	//cout << A.cloneGra



	//vector<vector<int>> matrix{ {1,0,1},{0,-2,3} };
	//cout << A.maxSumSubmatrix(matrix, 2) << endl;

	//set<int> test{ 1,2,3,4 };
	//auto it = test.upper_bound(4);
	//auto it1 = test.lower_bound(2);
	//cout << *it << endl;
	//cout << *it1 << endl;

	return 0;
}