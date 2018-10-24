#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);
		int l1, l2, r1, r2;
		l1 = (A < E) ? E : A; 
		r1 = (C < G) ? C : G;
		l2 = (B < F) ? F : B;
		r2 = (D < H) ? D : H;
		if (l1 < r1 && l2 < r2)
			return area1 + area2 - (r1 - l1) * (r2 - l2);
		return area1 + area2;
	}

	string numberToWords(int num) {
		if (num == 0) return "Zero";
		return int_string(num).substr(1);
	}

	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<int> temp(nums.size(), 0);
		vector<int> parent(nums.size(), 0);

		int max_len = 0, start = 0;
		for (int i = nums.size() - 1; i >= 0; --i) {
			for (int j = i; j < nums.size(); ++j) {
				if (nums[j] % nums[i] == 0 && temp[i] < 1 + temp[j]) {
					temp[i] = temp[j] + 1;
					parent[i] = j;

					if (temp[i] > max_len) {
						max_len = temp[i];
						start = i;
					}
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < max_len; ++i) {
			res.push_back(nums[start]);
			start = parent[start];
		}
		return res;
	}

	vector<int> largestDivisibleSubset1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> temp(nums.size(), 0);
		vector<int> parent(nums.size(), 0);

		int max_len = 0, pos = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i; j >= 0; --j) {
				if (nums[i] % nums[j] == 0 && temp[i] < temp[j] + 1) {
					temp[i] = temp[j] + 1;
					parent[i] = j;

					if (temp[i] > max_len) {
						max_len = temp[i];
						pos = i;
					}
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < max_len; ++i) {
			res.push_back(nums[pos]);
			pos = parent[pos];
		}
		return res;
	}



	bool checkPerfectNumber(int num) {
		int sum = 1;
		for (int i = 2; i <= (int)sqrt(num); ++i) {
			if (num / i * i == num)
				sum += num / i + i;
		}
		if (((int)sqrt(num)) * ((int)sqrt(num)) == num)
			sum -= (int)sqrt(num);
		return sum == num;
	}

	bool isPerfectSquare(int num) {
		//long long l = 0, r = num;
		//while (l <= r) {
		//	long long mid = (l + r) >> 1;
		//	long long sqmid = mid * mid;
		//	if (sqmid > num) r = mid - 1;
		//	else if (sqmid < num) l = mid + 1;
		//	else return true;
		//}
		//return false;

		//long r = num;
		//while (r * r > num)
		//	r = (r + num / r) / 2;
		//return r * r == num;

		int i = 1;
		while (num > 0) {
			num -= i;
			i += 2;
		}
		return num == 0;
	}


private:
	static const char * const below_20[];
	static const char * const below_100[];
	static string int_string(int num) {
		if (num >= 1000000000) return int_string(num / 1000000000) + " Billion" + int_string(num - 1000000000 * (num / 1000000000));
		else if (num >= 1000000) return int_string(num / 1000000) + " Million" + int_string(num - 1000000 * (num / 1000000));
		else if (num >= 1000) return int_string(num / 1000) + " Thousand" + int_string(num - 1000 * (num / 1000));
		else if (num >= 100) return int_string(num / 100) + " Hundred" + int_string(num - 100 * (num / 100));
		else if (num >= 20) return string(" ") + below_100[num / 10 - 2] + int_string(num - 10 * (num / 10));
		else if (num >= 1) return string(" ") + below_20[num - 1];
		else return "";
	}

};

const char * const Solution::below_20[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const char * const Solution::below_100[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

int main() {
	Solution A = Solution();

	/*cout << A.computeArea(0,0,0,0,-1,-1,1,1) << endl;*/

	//cout << A.numberToWords(123) << endl;
	//cout << A.numberToWords(12345) << endl;
	//cout << A.numberToWords(1234567) << endl;

	/*cout <<A.isPerfectSquare(100000000)<< endl;*/

	vector<int> nums{ 1,3 };
	vector<int> res = A.largestDivisibleSubset1(nums);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;



	return 0;
}