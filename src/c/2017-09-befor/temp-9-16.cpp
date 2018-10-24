#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		//int len = buildings.size();
		//int left = INT_MAX, right = 0;
		//vector<int> index(2 * len, 0);
		//for (int i = 0; i < len; ++i) {
		//	index[i] = buildings[i][0];
		//	index[i + len] = buildings[i][1];
		//}
		//sort(index.begin(), index.end());

		//vector<pair<int, int>> res;
		//for (int i = 0; i < 2 * len; ++i) {
		//	int hi = 0;
		//	for (int j = 0; j < len; ++j) {
		//		if (index[i] >= buildings[j][0] && index[i] < buildings[j][1])
		//			hi = max(hi, buildings[j][2]);
		//		if (index[i] < buildings[j][0])
		//			break;
		//	}
		//	if (res.size() == 0)
		//		res.push_back(make_pair(index[i], hi));
		//	else {
		//		int old_hi = res.back().second;
		//		if (hi < old_hi)
		//			res.push_back(make_pair(index[i], hi));
		//		if (hi > old_hi)
		//			res.push_back(make_pair(index[i], hi));
		//	}
		//}
		//return res;


	}

private:

};

class TrieNode {
public:
	TrieNode *next[26];
	bool is_word;

	TrieNode(bool b = false) {
		memset(next, 0, sizeof(next));
		is_word = b;
	}
};

class Trie {
private:
	TrieNode *root;
public:
	/* Initialize your data sturcture here.*/
	Trie() {
		root = new TrieNode();
	}

	/* Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == NULL)
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->is_word = true;
	}

	/* Returns if the word is in the trie*/
	bool search(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == NULL)
				return false;
			p = p->next[word[i] - 'a'];
		}
		return p != NULL && p->is_word;
	}

	/* Returns if there is any word in the trie that starts with the given prefix.*/
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (p->next[prefix[i] - 'a'] == NULL)
				return false;
			p = p->next[prefix[i] - 'a'];
		}
		return true;
	}
};


class DictNode {
public:
	DictNode *next[26];
	bool is_word;
	DictNode() {
		memset(next, 0, sizeof(next));
		is_word = false;
	}
};

class WordDictionary {
private:
	DictNode * root;
public:
	WordDictionary() {
		root = new DictNode();
	}

	void addWord(string word) {
		DictNode* node = root;
		for (int i = 0; i < word.size(); ++i) {
			if (node->next[word[i] - 'a'] == NULL)
				node->next[word[i] - 'a'] = new DictNode();
			node = node->next[word[i] - 'a'];
		}
		node->is_word = true;
	}

	bool search(string word) {
		return help_search(root, word, 0);
	}

private:
	bool help_search(DictNode* head, string& word, int pos) {
		if (pos == word.size())
			return head != NULL && head->is_word;

		if (word[pos] == '.') {
			for (int i = 0; i < 26; ++i) {
				if (head->next[i] != NULL)
					if (help_search(head->next[i], word, pos + 1))
						return true;
			}
			return false;
		}

		if (head->next[word[pos] - 'a'] == NULL)
			return false;
		
		return help_search(head->next[word[pos] - 'a'], word, pos + 1);
	}

};

int main() {
	Solution A = Solution();

	vector<vector<int>> buildings{ {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
	vector<pair<int, int>> res = A.getSkyline(buildings);

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << "  " << res[i].second << endl;
	}

	return 0;
}