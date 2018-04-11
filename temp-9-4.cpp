#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {

	}

	char findTheDifference(string s, string t) {
		//vector<int> res(27, 0);
		//for (int i = 0; i < s.size(); ++i) {
		//	res[s[i] - 'a'] ++;
		//	res[t[i] - 'a'] --;
		//}
		//res[t[t.size() - 1] - 'a'] --;
		//for (int i = 0; i < 27; ++i)
		//	if (res[i] == -1)
		//		return i + 'a';
		char r = 0;
		for (char c : s) r ^= c;
		for (char c : t) r ^= c;
		return r;
	}

	bool isPowerofTwo(int n) {
		//while (n) {
		//	if (n & 1)
		//		break;
		//	n = n >> 1;
		//}
		//return n == 1;

		return n > 0 && !(n&(n - 1));
	}

	int rangeBitwiseAnd(int m, int n) {
		//int temp = n - m;
		//int temp2 = -2;
		//while (temp) {
		//	temp = temp >> 1;
		//	n = n & temp2;
		//	temp2 = temp2 << 1;
		//}
		//return n;

		// return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;

		//if (m == 0) return 0;
		//int fact = 1;
		//while (m != n) {
		//	m >>= 1;
		//	n >>= 1;
		//	fact <<= 1;
		//}
		//return m * fact;

		while (m < n) n = n & (n - 1);
		return n;
	}

	vector<int> countBits(int num) {
		//vector<int> res(num + 1, 0);
		//if (num == 0) return res;
		//res[1] = 1;
		//int flag = 4;
		//for (int i = 2; i <= num; ++i) {
		//	if (i < flag)
		//		res[i] = 1 + res[~(flag >> 1) & i];
		//	else {
		//		res[i] = 1;
		//		flag <<= 1;
		//	}
		//}
		//return res;

		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; ++i) res[i] += res[i&(i - 1)] + 1;
		// for (int i = 1; i <= num; ++i) res[i] = res[i>>1] + (i & 1);
		return res;
	}

	string toHex(int num) {
		const string HEX = "0123456789abcdef";
		if (num == 0) return "0";
		string res;
		int count = 0;
		while (num && count++ < 8) {
			res = HEX[(num & 0xf)] + res;
			num >>= 4;
		}
		return res; 
	}
};


int main() {
	Solution A = Solution();

	cout << A.toHex(-1) << endl;

	//vector<int> res = A.countBits(12);
	//for (int i = 0; i < res.size(); ++i) {
	//	cout << res[i] << " ";
	//}


	//cout << A.rangeBitwiseAnd(0, 3) <<endl;

	//int temp = 2147483647;
	//for (int i = 0; i < 4; ++i) {
	//	temp = temp << 1;
	//	cout << temp << endl;
	//}

	//cout << A.isPowerofTwo(1) << endl;
	//cout << A.isPowerofTwo(2) << endl;
	//cout << A.isPowerofTwo(3) << endl;
	//cout << A.isPowerofTwo(4) << endl;
	//cout << A.isPowerofTwo(2048) << endl;


	//string s = "abcd";
	//string t = "zabcd";
	//cout << A.findTheDifference(s, t) << endl;

	return 0;
}