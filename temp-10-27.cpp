#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		n += (n >> 1) + 1;
		return n&(n - 1) == 0;
	}

	int integerReplacement(int n) {
		if (n == 1) return 0;
		if (n == INT_MAX) return 32;
		if (n % 2 == 0) return integerReplacement(n / 2) + 1;
		return min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
	}

	string originalDigits(string s) {
		vector<int> letters(26, 0);
		vector<int> digits(10, 0);
		for (auto c : s)
			++letters[c - 'a'];

		string inorder = "zwxgufvroi";
		string nums = "0268457319";
		vector<string> temp{ "ero", "to", "si", "eiht", "for", "ive", "seen", "thee", "ne", "nne" };
		for (int i = 0; i < 10; ++i) {
			if (letters[inorder[i] - 'a'] == 0) continue;
			for (auto c : temp[i])
				letters[c - 'a'] -= letters[inorder[i] - 'a'];
			digits[nums[i] - '0'] = letters[inorder[i] - 'a'];
			letters[inorder[i] - 'a'] = 0;
		}

		string res = "";
		for (int i = 0; i < 10; ++i) {
			if (digits[i] == 0) continue;
			string num(digits[i], i + '0');
			res += num;
		}
		return res;
	
	}


private:
	int helper(uint32_t n) {
		if (n == 1) return 0;
		if (n % 2 == 0) return helper(n / 2) + 1;
		return min(helper(n + 1), helper(n - 1)) + 1;
	}

};

int main() {
	Solution A = Solution();

	//string s(1, 9 + '0');
	//cout << s << endl;
	cout << A.originalDigits("owoztneoer") << endl;
	cout << A.originalDigits("fivefuro") << endl;
	cout << A.originalDigits("one") << endl;
	cout << A.originalDigits("zero") << endl;


	//cout << A.integerReplacement(1) << endl;
	//cout << A.integerReplacement(8) << endl;
	//cout << A.integerReplacement(7) << endl;
	//cout << A.integerReplacement(0x7FFFFFFF)<< endl;


	//cout << A.hasAlternatingBits(5) << endl;
	//cout << A.hasAlternatingBits(7) << endl;
	//cout << A.hasAlternatingBits(11) << endl;
	//cout << A.hasAlternatingBits(10) << endl;
	//cout << A.hasAlternatingBits(0) << endl;
	//cout << A.hasAlternatingBits(1) << endl;


	return 0;
}