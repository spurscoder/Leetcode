#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;

	Employee(int a, int b, vector<int> c) :id(a), importance(b), subordinates(c) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> paths;
		vector<int> path;
		findPaths(root, sum, path, paths);
		return paths;
	}

	int getImportance(vector<Employee*> employees, int id) {
		set<int> touched;
		vector<int> find;
		int res = 0;
		helper(employees, id, touched, find, res);

		while (!find.empty()) {
			int temp = find[find.size() - 1];
			find.pop_back();
			if (touched.find(temp) != touched.end()) continue;
			helper(employees, temp, touched, find, res);
		}
		return res;
	}


	int getImportance1(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> pool;
		for (auto e : employees)
			pool[e->id] = e;
		return getSum(pool, id);
	}

	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int r_n = nums.size(), c_n = nums[0].size();
		if (r_n * c_n != r * c) return nums;

		vector<vector<int>> res;
		vector<int> temp;
		int count = 0;
		for (int i = 0; i < r_n; ++i) {
			for (int j = 0; j < c_n; ++j) {
				temp.push_back(nums[i][j]);
				++count;
				if (count == c) {
					count = 0;
					res.push_back(temp);
					temp.clear();
				}
			}
		}
		return res;
	}

private:
	int getSum(unordered_map<int, Employee*>& pool, int id) {
		int res = pool[id]->importance;
		for (auto e : pool[id]->subordinates)
			res += getSum(pool, e);
		return res;
	}
	void helper(vector<Employee*>& employees, int id, set<int>& touched, vector<int>& find, int &res) {
		for (auto employee : employees)
			if (employee->id == id) {
				touched.insert(id);
				res += employee->importance;
				for (auto member : employee->subordinates)
					find.push_back(member);
				return;
			}
		return;
	}
	void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths) {
		if (!root) return;
		path.push_back(root->val);
		if (!root->left && !root->right && sum == root->val)
			paths.push_back(path);
		findPaths(root->left, sum - root->val, path, paths);
		findPaths(root->right, sum - root->val, path, paths);
		path.pop_back();
	}

};

int main() {
	Solution A = Solution();

	vector<vector<int>> nums{ {1,2},{3,4} };

	vector<vector<int>> res1 = A.matrixReshape(nums, 1, 4);
	vector<vector<int>> res2 = A.matrixReshape(nums, 4, 1);
	vector<vector<int>> res3 = A.matrixReshape(nums, 2, 3);

	for (auto m : res1) {
		for (auto e : m)
			cout << e << " ";
		cout << endl;
	}
	for (auto m : res2) {
		for (auto e : m)
			cout << e << " ";
		cout << endl;
	}
	for (auto m : res3) {
		for (auto e : m)
			cout << e << " ";
		cout << endl;
	}



	//Employee* temp1 = new Employee(1, 5, vector<int>{2, 3});
	//Employee* temp2 = new Employee(2, 3, vector<int>());
	//Employee* temp3 = new Employee(3, 3, vector<int>());

	//vector<Employee*> temp;
	//temp.push_back(temp1);
	//temp.push_back(temp2);
	//temp.push_back(temp3);

	//for (auto mem : temp1->subordinates)
	//	cout << mem << " ";
	//cout << endl;

	//cout << A.getImportance(temp, 1) << endl;


	return 0;
}