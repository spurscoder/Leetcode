#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int len = s.size();
		vector<int> temp(len, 0);
		for (int i = len - 1; i >= 0; --i) {
			temp[i] = 1;
			int temp2 = 0, temp1;
			for (int j = i + 1; j < len; ++j) {
				if (s[i] == s[j])
					temp1 = temp2 + 2;
				else
					temp1 = max(temp[j], temp[j - 1]);
				temp2 = temp[j];
				temp[j] = temp1;
			}
		}
		return temp[len - 1];
	}

};

int main() {
	Solution A = Solution();

	string s = "bbbab";
	cout << A.longestPalindromeSubseq(s) << endl;

	return 0;
}