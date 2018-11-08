#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string s = "";

		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while (i >= 0 || j >= 0 || c == 1) {
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			s = char(c % 2 + '0') + s;
			c /= 2;
		}

		return s;
	}

	string addString(string num1, string num2) {
		string s = "";

		int c = 0, i = num1.size() - 1, j = num2.size() - 1;
		while (i >= 0 || j >= 0 || c == 1) {
			c += j >= 0 ? num2[j--] - '0' : 0;
			c += i >= 0 ? num1[i--] - '0' : 0;
			s = char(c % 10 + '0') + s;
			c /= 10;
		}

		return s;
	}

	int leastInterval(vector<char>& tasks, int n) {
		vector<int> temp(26, 0);
		int max_char = 0, m = 0;
		for (int i = 0; i < tasks.size(); ++i) {
			++temp[tasks[i] - 'A'];
			max_char = max(temp[tasks[i] - 'A'], max_char);
		}
		for (auto num : temp)
			if (num == max_char)
				++m;

		return max((max_char - 1) * (n + 1) + m, (int)tasks.size());
	}

	int numSquares(int n) {
		static vector<int> dp{ 0 };
		while (dp.size() <= n) {
			int m = dp.size(), squares = INT_MAX;
			for (int i = 1; i*i <= m; ++i)
				squares = min(squares, dp[m - i * i] + 1);
			dp.push_back(squares);
		}
		return dp[n];
	}

	int numSquares1(int n) {
		static vector<int> dp{ 0 };
		int m = dp.size();
		dp.resize(max(m, n + 1), INT_MAX);
		for (int i = 1, i2; (i2 = i*i) <= n; ++i)
			for (int j = max(m, i2); j <= n; ++j)
				if (dp[j] > dp[j - i2] + 1)
					dp[j] = dp[j - i2] + 1;
		return dp[n];
	}
};


int main() {
	Solution A = Solution();


	//cout << A.numSquares(1) << "  " << 1 << endl;
	//cout << A.numSquares(2) << "  " << 2 << endl;
	//cout << A.numSquares(3) << "  " << 3 << endl;
	//cout << A.numSquares(4) << "  " << 1 << endl;
	//cout << A.numSquares(5) << "  " << 2 << endl;
	//cout << A.numSquares(6) << "  " << 3 << endl;
	//cout << A.numSquares(8) << "  " << 2 << endl;
	//cout << A.numSquares(9) << "  " << 1 << endl;
	//cout << A.numSquares(12) << "  " << 3 << endl;
	//cout << A.numSquares(13) << "  " << 4 << endl;

	//vector<char> tasks{ 'A', 'B', 'C', 'D'};
	//cout << A.leastInterval(tasks, 3) << endl;

	return 0;
}