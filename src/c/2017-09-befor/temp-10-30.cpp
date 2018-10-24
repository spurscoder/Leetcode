#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		//string as = A;
		//for (int rep = 1; rep <= A.length() / B.length() + 2; ++rep, as += A)
		//	if (as.length() >= B.length() && as.find(B) != string::npos) return rep;
		//return -1;

		// Solution 2
		//for (int i = 0, j = 0; i < A.length(); ++i) {
		//	for (j = 0; j < B.length() && A[(i + j) % A.length()] == B[j]; ++j);
		//	if (j == B.length()) return (i + j) / A.length() + ((i + j) % A.length() != 0 ? 1 : 0);
		//}
		//return -1;
	
		// Solution 3
		vector<int> prefTable(B.length() + 1);
		for (auto sp = 1, pp = 0; sp < B.length(); prefTable[++sp] = pp)
			pp = B[pp] == B[sp] ? pp + 1 : prefTable[pp];

		for (auto p : prefTable)
			cout << p << " ";
		cout << endl;


		for (auto i = 0, j = 0; i < A.length(); i += max(1, j - prefTable[j]), j = prefTable[j]) {
			while (j < B.length() && A[(i + j) % A.length()] == B[j]) ++j;
			if (j == B.length()) return (i + j) / A.length() + ((i + j) % A.length() != 0 ? 1 : 0);
		}
		
		return -1;
	}

	bool repeatedSubstringPattern(string s) {
		for (int i = 1; i < s.length()/2 + 1; ++i) {
			if (s[i] == s[0] && s.length()%i == 0) {
				int j = i;
				for (; j < s.length(); ++j)
					if (s[j] != s[j%i])	break;
				if (j == s.length()) return true;
			}
		}
		return false;
	}
private:


};

int main() {
	Solution A = Solution();

	cout << A.repeatedSubstringPattern("aabaaba") << endl;
	cout << A.repeatedSubstringPattern("abababq") << endl;
	cout << A.repeatedSubstringPattern("abcabcabcab") << endl;
	cout << A.repeatedSubstringPattern("aann") << endl;



	//string a = "aab";
	//string b = "abaabaaba";

	//cout << A.repeatedStringMatch(a, b) << endl;

	return 0;
}