#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		int right = sqrt(c);
		int left = 0;
		while (left < right) {
			int sum = left * left + right * right;
			if (sum == c)
				return true;
			if (sum < c) ++left;
			if (sum > c) --right;
		}
		return false;
	}

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int result = inner_product(price.begin(), price.end(), needs.begin(), 0);
		for (auto spec : special) {
			int j = 0;
			vector<int> temp(needs.size(), 0);
			for (; j < needs.size(); ++j) {
				if (spec[j] > needs[j]) break;
				else
					temp[j] = needs[j] - spec[j];
			}
			if (j != needs.size()) continue;

			result = min(result, spec.back() + shoppingOffers(price, special, temp));

		}
		return result;
	}
private:

};

int main() {
	Solution A = Solution();

	vector<int> price{ 2,5 };
	vector<vector<int>> special{ {3,0,5}, {1,2,10} };
	vector<int> needs{ 3,2 };

	cout << A.shoppingOffers(price, special, needs) << endl;

	vector<int> price1{ 2,3,4 };
	vector<vector<int>> special1{ {1,1,0,4}, {2,2,1,9} };
	vector<int> needs1{ 1,2,1 };

	cout << A.shoppingOffers(price1, special1, needs1) << endl;

	vector<int> price2{ 9,9 };
	vector<vector<int>> special2{ {1,1,1} };
	vector<int> needs2{ 2,2 };
	cout << A.shoppingOffers(price2, special2, needs2) << endl;

	//cout << A.judgeSquareSum(5) << endl;
	//cout << A.judgeSquareSum(3) << endl;


	return 0;
}