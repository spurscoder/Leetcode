#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
		string res;
		for (int i = 0; i < nums.size(); ++i)
			res += to_string(nums[i]);
		return res[0] == '0' ? "0" : res;
	}

	int titleToNumber(string s) {
		int len = s.length();
		int res = 0;
		for (int i = 0; i < len; ++i) {
			res = res * 26 + (s[i] - 'A' + 1);
		}
		return res;
	}

	string convertToTitle(int n) {
		return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
	}

	int findComplement(int num) {
		unsigned mask = ~0;
		while (num & mask) mask <<= 1;
		return ~mask & ~num;
	}

	bool judgeCircle(string moves) {
		int lr = 0, ud = 0;
		for (int i = 0; i < moves.length(); ++i) {
			switch (moves[i]) {
			case 'U': ++ud; break;
			case 'D': --ud; break;
			case 'L': --lr; break;
			case 'R': ++lr; break;
			default:continue;
			}
		}
		return lr == 0 && ud == 0;
	}



private:
	static bool cmp(int a, int b) {
		string left = to_string(a);
		string right = to_string(b);

		return left + right > right + left;
	}

};

int main() {
	Solution A = Solution();


	//cout << endl;
	//string te = "ASDFGH";
	//cout << te.find('I') << endl;
	//cout << A.judgeCircle("UD") << endl;
	//cout << A.judgeCircle("LL") << endl;
	//cout << A.judgeCircle("UDD") << endl;
	//cout << A.judgeCircle("LLRR") << endl;


	//cout << A.findComplement(5) << endl;


	//cout << A.convertToTitle(1) << endl;
	//cout << A.convertToTitle(26) << endl;
	//cout << A.convertToTitle(27) << endl;
	//cout << A.convertToTitle(53) << endl;

	//cout << A.titleToNumber("A") << endl;
	//cout << A.titleToNumber("AA") << endl;
	//cout << A.titleToNumber("AB") << endl;
	//cout << A.titleToNumber("BA") << endl;


	//vector<int> nums{9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
	//vector<int> nums1{ 121, 12 };
	//cout << A.largestNumber(nums1) << endl;
//	"995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014"
//	"995998549642963295795569525905189958985890288238775871870185978591838283748308308827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014"
//	"995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014"
	return 0;
}