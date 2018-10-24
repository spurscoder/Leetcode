#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int* getNext(string b) {
		int len = b.length();
		int j = 0;

		int *next = new int[len + 1];
		next[0] = next[1] = 0;

		for (int i = 1; i <= len; ++i) {
			while (j > 0 && b[i] != b[j]) j = next[j];
			if (b[i] == b[j]) ++j;
			next[i + 1] = j;
		}
		return next;
	}

	int* Next(string b) {
		int len = b.length();
		int j = 0;

		int* next = new int[len + 1];
		next[0] = next[1] = 0;

		for (int i = 1; i <= len; ++i) {
			while (j > 0 && b[i] != b[j]) j = next[j];
			if (b[i] == b[j]) ++j;
			next[i + 1] = j;
		}
		return next;
	}

	void find(string ori_str, string cur_str, int *next) {
		int j = 0; 
		for (int i = 0; i < ori_str.length(); ++i) {
			while (j > 0 && ori_str[i] != cur_str[j])
				j = next[j];
			if (ori_str[i] == cur_str[j]) ++j;
			if (j == cur_str.length()) {
				cout << "Position:" << i - j + 1 << endl;
				j = next[j];
			}
		}
	}

	void search(string original, string find, int *next) {
		int j = 0;
		for (int i = 0; i < original.size(); ++i) {
			while (j > 0 && original[i] != find[j])
				j = next[j];
			if (original[i] == find[j]) ++j;
			if (j == find.length()) {
				cout << "Position: " << i - j + 1 << endl;
				j = next[j];
			}
		}
	}



private:



};

int main() {
	Solution A = Solution();

	int *next = A.Next("ababcda");
	A.find("ababcda", "ab", next);

	return 0;
}