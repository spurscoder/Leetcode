#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct TrieNode {
	TrieNode* next[26];
	string word;
	TrieNode() :next(), word("") {};
};


class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		return helper(nums, 0, nums.size()-1);
	}

	bool exist(vector<vector<char>>& board, string word) {
		set<pair<int, int>> temp;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == word[0]) {
					if (help_exist(board, word.substr(1), temp, i, j))
						return true;
				}
			}
		return false;
	}

	TrieNode* buildTrie(vector<string>& words) {
		TrieNode* root = new TrieNode();
		for (auto word : words) {
			TrieNode *p = root;
			for (int i = 0; i < word.size(); ++i) {
				int pos = word[i] - 'a';
				if (p->next[pos] == NULL) p->next[pos] = new TrieNode();
				p = p->next[pos];
			}
			p->word = word;
		}
		return root;
	}


	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		TrieNode* root = buildTrie(words);
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j) {
				dfs(board, i, j, root, res);
			}
		return res;
	}

private:
	void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& res) {
		char c = board[i][j];
		if (c == '#' || root->next[c - 'a'] == NULL) return;
		root = root->next[c - 'a'];
		if (root->word != "") {
			res.push_back(root->word);
			root->word = "";
		}

		board[i][j] = '#';
		if (i > 0) dfs(board, i - 1, j, root, res);
		if (j > 0) dfs(board, i, j - 1, root, res);
		if (i < board.size() - 1) dfs(board, i + 1, j, root, res);
		if (j < board[0].size() - 1) dfs(board, i, j + 1, root, res);
		board[i][j] = c;

	}

	bool help_exist(vector<vector<char>>& board, string word, set<pair<int,int>> temp, int i, int j) {
		temp.insert(make_pair(i, j));
		if (!word.length()) return true;
		if (j - 1 >= 0 && board[i][j - 1] == word[0] && temp.find(make_pair(i,j-1)) == temp.end() && help_exist(board, word.substr(1), temp, i, j - 1)) return true;
		if (j + 1 <= board[0].size() - 1 && board[i][j + 1] == word[0] && temp.find(make_pair(i, j + 1)) == temp.end() && help_exist(board, word.substr(1), temp, i, j + 1)) return true;
		if (i - 1 >= 0 && board[i - 1][j] == word[0] && temp.find(make_pair(i - 1, j)) == temp.end() && help_exist(board, word.substr(1), temp, i - 1, j)) return true;
		if (i + 1 <= board.size() - 1 && board[i + 1][j] == word[0] && temp.find(make_pair(i + 1, j)) == temp.end() && help_exist(board, word.substr(1), temp, i + 1, j)) return true;
		return false;
	}


	int helper(vector<int>& nums, int left, int right) {
		if (left > right) return -1;
		
		int mid = (left + right) / 2;
		if ((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) || 
			(mid != 0 && mid != nums.size()-1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]))
			return mid;

		int left1 = helper(nums, left, mid - 1);
		if (left1 != -1) return left1;
		
		int right1 = helper(nums, mid + 1, right);
		if (right1 != -1) return right1;
		
		return -1;
	}

};


int main() {
	Solution A = Solution();

	vector<vector<char>> board{ {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h','k','r'}, {'i','f','l','v'} };
	vector<string> words{ "oath", "pea", "eat", "rain" };
	vector<string> res = A.findWords(board, words);
	for (auto word : res)
		cout << word << endl;

	//vector<vector<char>> board{ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A','D','E','E'} };
	//vector<vector<char>> board1{ {'a', 'b'}, {'c', 'd'} };
	//cout << A.exist(board1, "acdb") << endl;

	/*cout << A.exist(board, "ABCCED") << endl;
	cout << A.exist(board, "SEE") << endl;
	cout << A.exist(board, "ABCB") << endl;
*/

	//vector<int> nums{ 1 };
	//cout << A.findPeakElement(nums) << endl;



	return 0;
}