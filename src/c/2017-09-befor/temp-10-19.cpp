#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	string solveEquation(string equation) {
		vector<int> left(2, 0);
		check(equation.substr(0, equation.find('=')), left);

		vector<int> right(2, 0);
		check(equation.substr(equation.find('=') + 1), right);

		left[0] = left[0] - right[0];
		left[1] = right[1] - left[1];

		if (left[0] == 0 && left[1] == 0)
			return "Infinite solutions";
		else if (left[0] == 0 && left[1] != 0)
			return "No solution";
		else
			return "x=" + to_string(left[1] / left[0]);
	}

	bool find132pattern(vector<int>& nums) {
		int s3 = INT_MIN;
		stack<int> st;
		for (int i = nums.size() - 1; i >= 0; --i){
			if (nums[i] < s3) return true;
			else while (!st.empty() && nums[i] > st.top()) {
				s3 = st.top(); st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
private:
	void check(string equ, vector<int>& coef) {
		int symbol = 1, cur = 0;
		for (int i = 0; i < equ.length(); ++i) {
			switch (equ[i]) {
			case '+':
				symbol = 1;
				if (cur != 0) {
					coef[1] += cur;
					cur = 0;
				}
				break;
			case '-':
				symbol = -1;
				if (cur != 0) {
					coef[1] += cur;
					cur = 0;
				}
				break;
			case 'x':
				if (i-1 >= 0 && equ[i-1] >= '0' && equ[i-1] <= '9') {
					coef[0] += cur;
				} else {
					coef[0] += symbol;
				}
				cur = 0;
				break;
			default:
				cur = cur * 10 + symbol * (equ[i] - '0');
				break;
			}
		}
		if (cur != 0)
			coef[1] += cur;
	}


};

int main() {
	Solution A = Solution();

	//vector<int> nums{ 1,2,3,4 };
	//vector<int> nums1{ 3,1,4,2 };
	//vector<int> nums2{ -1, 3,2,0 };
	vector<int> nums3{ 1,0,1,-4,-3 };
	//cout << A.find132pattern(nums) << endl;
	//cout << A.find132pattern(nums1) << endl;
	//cout << A.find132pattern(nums2) << endl;
	cout << A.find132pattern(nums3) << endl;

	//string equation = "x+5-3+x=6+x-2";
	//string equation1 = "x=x";
	//string equation2 = "2x=x";
	//string equation3 = "2x+3x-6x=x+2";
	//string equation4 = "x=x+2";

	//string temp = "0x=0";

	//cout << A.solveEquation(temp) << endl;

	//cout << A.solveEquation(equation) << endl;
	//cout << A.solveEquation(equation1) << endl;
	//cout << A.solveEquation(equation2) << endl;
	//cout << A.solveEquation(equation3) << endl;
	//cout << A.solveEquation(equation4) << endl;
 //

	//string test = "qwert";
	//cout << test.find('e') << endl;
	//cout << test.substr(0, test.find('e')) << endl;
	//cout << test.substr(test.find('e') + 1) << endl;



	return 0;
}