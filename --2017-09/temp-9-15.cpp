#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		helper(s, res, 0, 0, '(', ')');
		return res;
	}

	vector<string> removeInvalidParentheses2(string s) {
		vector<string> res;

		if (s == "") return res;

		unordered_set<string> visited;
		queue<string> queue;
		queue.push(s);
		visited.insert(s);
		bool found = false;
		while (!queue.empty()) {
			s = queue.front();
			queue.pop();

			if (isValid(s)) {
				found = true;
				res.push_back(s);
			}

			if (found) continue;

			for (int i = 0; i < s.size(); ++i) {
				if (s[i] != '(' && s[i] != ')') continue;

				string temp = s.substr(0, i) + s.substr(i + 1, s.length() - i - 1);

				if (visited.find(temp) == visited.end()) {
					queue.push(temp);
					visited.insert(temp);
				}
			}
		}
		return res;
	}

	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (!row) return 0;
		int col = grid[0].size();
		int res = 0;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1') {
					++res;
					helper_islands(grid, i, j, row, col);
				}
			}
		return res;
	}
private:
	void helper_islands(vector<vector<char>>& grid, int i, int j, int row, int col) {
		if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;
		grid[i][j] = '0';
		helper_islands(grid, i - 1, j, row, col);
		helper_islands(grid, i, j - 1, row, col);
		helper_islands(grid, i + 1, j, row, col);
		helper_islands(grid, i, j + 1, row, col);
	}

	bool isValid(string s) {
		int len = s.length();
		int count = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(') count++;
			if (s[i] == ')') count--;
			if (count < 0) return false;
		}
		return count == 0;
	}


	void helper(string s, vector<string>& res, int i_temp, int j_temp, char l, char r) {
		for (int count = 0, i = i_temp; i < s.size(); ++i) {
			if (s[i] == l) ++count;
			if (s[i] == r) --count;
			if (count >= 0) continue;
			for (int j = j_temp; j <= i; ++j)
				if (s[j] == r && (j == j_temp || s[j - 1] != r))
					helper(s.substr(0, j) + s.substr(j + 1, s.length() - j - 1), res, i, j, l, r);
			return;
		}
		reverse(s.begin(), s.end());
		if (l == '(')
			helper(s, res, 0, 0, ')', '(');
		else
			res.push_back(s);
	}


};




//class Trie {
//public:
//	Trie() {
//		return Trie;
//	}
//
//	void insert(string word) {
//		str.push_back(word);
//	}
//
//	bool search(string word) {
//		for (int i = 0; i < str.size(); ++i) {
//			if(str[i] == word)
//				return true;
//		}
//		return false;
//	}
//
//	bool startsWith(string prefix) {
//		int len = prefix.size();
//		for (int i = 0; i < str.size(); ++i) {
//			if (len <= str[i].length() && str[i].substr(0, len) == prefix)
//				return true;
//		}
//		return false;
//	}
//
//private:
//	vector<string> str;
//};

int main() {
	Solution A = Solution();

	vector<vector<char>> grid{ {'1', '1', '1', '1', '1'}, {'0', '0', '1', '0', '0'}, {'1', '1', '1', '0', '1'} };
	cout << A.numIslands(grid) << endl;






	//string s = "(()))";
	//string s1 = "(a)())()";
	//string s2 = "())())";
	//vector<string> res = A.removeInvalidParentheses2(s1);
	//cout << res.size() << endl;
	//cout << res[0] << " " << res[1] << endl;



	return 0;
}