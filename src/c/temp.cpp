#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**

//------------------------------------------------
int lengthOfLongestSubstring(string s){

int length = s.length();
if (length == 0) return 0;
if (length == 1) return 1;

int i = 0;
int j = 0;
bool Flag = true;
int result = 1;

for( ; i <= j && j < length; ){
Flag = true;
for(int temp = i; temp < j ; temp++)
{
if (s[temp] == s[j])
{
Flag = false;
break;
}
}
if (!Flag) i++;
else{
result = max(result, j-i+1);
j++;
}
}
return result;
}
int lengthOfLongestSubstring1(string s) {
vector<int> dict(256, -1);
int maxLen = 0, start = -1;
for (int i = 0; i != s.length(); i++) {
if (dict[s[i]] > start)
start = dict[s[i]];
dict[s[i]] = i;
maxLen = max(maxLen, i - start);
}
return maxLen;
}

//------------------------------------------------
double findMaxAverage(vector<int>& nums, int k) {
int max_aver = 0;
int temp = 0;
for (int i = 0; i < k; ++i) {
temp += nums[i];
}
for (int i = k; i < nums.size(); i++) {
cout << temp << ' ';
temp -= nums[i-k];
cout << temp << ' ';
temp += nums[i];
cout << temp << endl;
max_aver = max(max_aver, temp);
}
return double(max_aver) / k;
}

//---------------------------------------------
int maximumProduct(vector<int>& nums) {
int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
int temp;
for (int i = 0; i < nums.size(); ++i) {
temp = nums[i];
if (temp > max1) { max3 = max2; max2 = max1; max1 = temp;}
else if (temp > max2) {max3 = max2; max2 = temp;}
else if (temp > max3) {max3 = temp;}
if (temp < min1) {min2 = min1; min1 = temp;}
else if (temp < min2) {min2 = temp;}
}

cout << max1 <<' '<< max2 <<' '<< max3 <<' '<< min1 <<' '<< min2 << endl;

if (max3 > 0 || max1 <= 0) return max(max1*max2*max3, max1*min1*min2);
else if (max1 > 0) return max1*min1*min2;


}

//---------------------------------------------
int findUnsortedSubarray(vector<int>& nums) {
vector<int> temp = nums;
sort(nums.begin(), nums.end());
int left=-1, right=-2;
for (int i = 0; i < nums.size(); ++i) {
if (temp[i] != nums[i]) {
left = i;
break;
}
}
for (int i = nums.size()-1; i >= 0; --i) {
if (temp[i] != nums[i]) {
right = i;
break;
}
}
return right - left + 1;
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
flowerbed.insert(flowerbed.begin(),0);
flowerbed.push_back(0);
for(int i = 1; i < flowerbed.size()-1; ++i)
{
if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
{
--n;
++i;
}

}
return n <=0;
}

// ***********************************************
string convert(string s, int numRows) {
if (numRows == 1) return s;
int n = s.length();
string res;
bool flag = true;

for (int j = 0; j < n; ) {
res += s[j];
j += 2*numRows - 2;
}

for (int i = 1, j = 1; i < numRows - 1; ) {
res += s[j];
j = flag ? j + 2*(numRows - i - 1) : j + 2 * i;
flag = !flag;

if (j >= n) {
flag = true;
++ i;
j = i;
}
}

for (int j = numRows - 1; j < n; ) {
res += s[j];
j += 2 * numRows - 2;
}

return res;
}

// ***********************************************
vector<string> letterCombinations(string digits) {
vector<string> result;
if (digits.empty()) return result;
static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
result.push_back("");  // add a seed for the initial case
for (int i = 0; i < digits.size(); ++ i) {
int num = digits[i] - '0';
if (num < 0 || num > 9) break;
const string& candidate = v[num];
if (candidate.empty()) continue;
vector<string> tmp;
for ( int j = 0; j < candidate.size(); ++j) {
for (int k = 0; k < result.size(); ++k) {
tmp.push_back(result[k] + candidate[j]);
}
}
result.swap(tmp);
}
return result;
}


//************************************************
int reverse(int x) {
long long res = 0;
while (x) {
int temp = x%10;
res = res*10 + temp;
cout << temp << "**";
x /= 10;
cout << x << endl;
}
return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

//**************************************************
int myAtoi(string str) {
int len = str.size();
long long res = 0;
int i = 0;
int sign = 1;
for ( ; i < len ; ++ i) {
if (str[i] != ' ')
break;
}
if (i == len) return 0;
if (str[i] == '-') { sign = -1; ++ i;}
else if (str[i] == '+') ++i;

for ( ; i < len ; ++ i) {
if (str[i]-'0' >= 0 && str[i]-'0' <= 9)
res = res * 10 + (str[i] - '0');
else
break;
if (sign*res > 2147483647) return INT_MAX;
if (sign*res < -2147483648) return INT_MIN;
}

return sign*res;
}

//********************************************************
bool isNumber(string s) {
int i = s.find_first_not_of(' ');

// check the signficand
if (s[i] == '+' || s[i] == '-') ++i;

int n_num = 0, n_pt = 0;
for (; isdigit(s[i]) || s[i] == '.'; ++i)
s[i]=='.'?n_pt++:n_num++;
if (n_pt>1 || n_num < 1)
return false;

if (s[i] == 'e') {
i++;
if (s[i] == '+' || s[i] == '-') ++i;

int n_num = 0;
for (; s[i] >= '0' && s[i] <= '9'; ++i, n_num++) {}
if (n_num < 1) return false;
}

for (; s[i] == ' '; ++i) {}

return i == s.length();

}

bool isNumber1(string str){
int state = 0, flag = 0; //flag to judge the special case "."
while (str[0] == ' ') str.erase(0, 1); //delete the prefix whitespace
while (str[str.length() - 1] == ' ') str.erase(str.length()-1, 1); // delete the suffix whitespace

for (int i = 0; i < str.length(); ++i) {
if ('9' <= str[i] && str[i] <= '9') {
flag = 1;
if (state <= 2) state = 2;
else
state=(state<=5)?5:7;
}
else if ('+' == str[i] || '-' == str[i]) {
if (state == 0 || state == 3 ) state++;
else return false;
}
else if ('.' == str[i]) {
if (state <= 2 ) state = 6;
else return false;
}
else if ('e' == str[i]) {
if (flag && (state == 2 || state == 6 || state == 7)) state = 3;
else return false;
}
else return false;
}
return (state == 2 || state == 5 || state == 7 || (flag&&state==6));
}


int countNumbersWithUniqueDigits(int n) {
if (n == 0) return 1;
int res = 10;
int uniqueDigits = 9;
int availableNumber = 9;
while(n-- > 1 && availableNumber > 0) {
uniqueDigits = uniqueDigits * availableNumber;
res += uniqueDigits;
availableNumber--;
}
return res;

}


//***************************************
bool isPalindrome(int x) {
stringstream ss;
ss << x;
string s = ss.str();
for (int i = 0, j = s.length() - 1; i <= j; ++i, --j) {
if (s[i] != s[j])
return false;
}
return true;
}

bool isPalindrome1(int x) {
if (x < 0 || (x!=0 && x%10 == 0)) return false;
int sum = 0;
while (x > sum) {
sum = sum*10 + x%10;
x = x/10;
}
return (x == sum) || (x == sum/10);
}

//***************************************
typedef struct ListNode{
int val;
ListNode *next;

} ListNode;

ListNode* reverseList(ListNode* head){

ListNode* pre = NULL,* next = NULL;
while(head != NULL) {
next = head->next;
head->next = pre;
pre = head;
head = next;
}
return pre;
}

bool isPalindrome(ListNode * head) {
if (head == NULL || head->next == NULL)
return true;
ListNode* slow = head,* fast = head;
while (fast->next != NULL && fast->next->next != NULL) {
slow = slow->next;
fast = fast->next->next;
}
slow->next = reverseList(slow->next);
slow = slow->next;
while (slow != NULL) {
if (head->val != slow->val)
return false;
head = head->next;
slow = slow->next;
}
return true;
}


//***************************************
bool isPalindrome(string s) {
for (int i = 0, j = s.length()-1; i <= j; ++i, --j) {
while (!isdigit(s[i]) && !isalpha(s[i])) ++i;
while (!isdigit(s[j]) && !isalpha(s[j])) --j;
if (tolower(s[i]) != tolower(s[j])) return false;
}
return true;
}

bool isValid(string s) {
int len = s.length();
int num[len], index = 0;
for (int i = 0; i < len; ++i) {
if (s[i] == '(' || s[i] == '{' || s[i] == '[')
num[index++] = i;
else {
--index;
if (index < 0) return false;
switch (s[num[index]]) {
case '(': if (s[i] != ')') return false; break;
case '{': if (s[i] != '}') return false; break;
case '[': if (s[i] != ']') return false; break;
}
}
}
if (index == 0) return true;
return false;
}

//**************************************
void helper(unordered_set<vector<int> > &res, vector<int> temp, vector<int> &nums, int k) {
if (k >= nums.size()) {
res.insert(temp);
cout << k << endl;
return;
}
temp.push_back(nums[k]);
helper(res, temp, nums, k+1);
temp.pop_back();
helper(res, temp, nums, k+1);
}
vector<vector<int>> subsetsWithDup(vector<int> & nums) {
unordered_set<vector<int> > res;
vector<int> temp;
helper(res, temp, nums, 0);
return vector<vector<int> >(res.begin(), res.end());
}

*/

/*
//************************2017-8-23
int maxArea(vector<int>& height) {
int water = 0;
int i = 0, j = height.size() - 1;
while (i < j) {
int h = min(height[i], height[j]);
water = max(water, (j-i)*h);
while (height[i] <= h && i < j) ++i;
while (height[j] <= h && i < j) --j;
}
return water;
}


vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
vector<vector<int>> res;
if (root == NULL) return res;
queue<TreeNode*> temp;
temp.push(root);
bool flag = true;
while(!temp.empty()) {
int size = temp.size();
vector<int> row(size);
for (int i = 0; i < size; ++i) {
TreeNode *node = temp.front();
temp.pop();

int index = (flag) ? i : (size - i - 1 );

row[index] = node->val;
if (node->left) temp.push(node->left);
if (node->right) temp.push(node->right);
}
flag = !flag;
res.push_back(row);
}
return res;
}
*/

/*
//***************************2017-8-24

//**************************************
vector<vector<int>> levelOrder(TreeNode* root) {
vector<vector<int>> res;
if (root == NULL) return res;
queue<TreeNode* > temp;
temp.push(root);
while (!temp.empty()) {
int size = temp.size();
vector<int> row(size);
for (int i = 0; i<size; ++i) {
TreeNode * node = temp.front();
temp.pop();
row[i] = node->val;
if (node->left) temp.push(node->left);
if (node->right) temp.push(node->right);
}
res.push_back(row);
}
return res;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
vector<vector<int>> res;
if (root == NULL) return res;
queue<TreeNode*> que;
que.push(root);
stack<vector<int>> sta;
while (!que.empty()) {
int size = que.size();
vector<int> row(size);
for (int i = 0; i < size; ++i) {
TreeNode* node = que.front();
que.pop();
row[i] = node->val;
if (node->left) que.push(node->left);
if (node->right) que.push(node->right);
}
//res.push_back(row);
sta.push(row);
}
while (!sta.empty()) {
res.push_back(sta.top());
sta.pop();
}
return res;
}
vector<double> averageOfLevels(TreeNode* root) {
vector<double> res;
if (root == NULL) return res;
queue<TreeNode*> que;
que.push(root);
while (!que.empty()) {
int size = que.size();
double temp = 0;
for (int i = 0; i < size; ++i) {
TreeNode* node = que.front();
que.pop();
temp += node->val;
if (node->left) que.push(node->left);
if (node->right) que.push(node->right);
}
res.push_back(double(temp) / size);
}
return res;
}



vector<TreeNode* > helper(int beg, int en) {
vector<TreeNode*> res;
if (beg > en) return vector<TreeNode*>(1, NULL);


for (int i = beg; i <= en; ++i ) {
vector<TreeNode*> left, right;
left = helper(beg, i - 1);
right = helper(i + 1, en);
for (int j = 0; j < left.size(); ++j) {
for (int k = 0; k < right.size(); ++k) {
TreeNode* root = new TreeNode(i);
root->left = left[j];
root->right = right[k];
res.push_back(root);
}
}
}
return res;
}


vector<TreeNode*> generateTrees(int n) {
if (n == 0) return vector<TreeNode*>();
return helper(1, n);
}

int helper1(int beg, int en) {
if (beg > en) return 1;
int res = 0;
for (int i = beg; i <= en; ++i) {
int l = helper1(beg, i-1);
int r = helper1(i+1, en);
res += l*r;
}
return res;
}

int numTrees(int n) {
if (n==0)return 0;
return helper1(1, n);
}

int numTrees1(int n) {
vector<int> res(n + 1,0);
res[0] = 1; res[1] = 1;
for (int i = 2; i < n+1; ++i) {
for (int j = 0; j < i; ++j) {
res[i] += res[j] * res[i-j-1];
}
}
return res[n];
}



vector<int> diffWaysToCompute(string input) {
vector<int> res;
int size = input.size();
for (int i = 0; i < size; ++i) {
char cur = input[i];
if (cur == '-' || cur == '+' || cur == '*') {
vector<int> res1 = diffWaysToCompute(input.substr(0, i));
vector<int> res2 = diffWaysToCompute(input.substr(i+1));
for (auto a:res1) {
for (auto b:res2) {
switch(cur){
case '+': res.push_back(a+b); break;
case '-': res.push_back(a-b); break;
case '*': res.push_back(a*b); break;
}
}
}
}
}
if (res.empty()) res.push_back(atoi(input.c_str()));
return res;
}

bool canPartition(vector<int>& nums) {
int sum = accumulate(nums.begin(), nums.end(), 0);
bitset<10001> bits(1);
for (auto n:nums) bits |= bits << n;
return !(sum & 1) && bits[sum >> 1];
}

bool wordBreak(string s, vector<string>& wordDict) {
if (dict.size() == 0) return false;

vector<bool> dp(s.size()+1, false);
dp[0] = true;
for(int i = 1; i <= s.size(); ++i)
for (int j = i-1; j >= 0; --j)
if (dp[j]) {
string word = s.substr(j,i-j);
if (dict.find(word) != dict.end()) {
dp[i] = true;
break;
}
}
return dp[s.size()];

}*/

// 2017-8-26

// 1
//vector<int> smallestRange(vector<vector<int>>& nums) {
//	int k = nums.size(), left = -100000, left1, right1, right = 100000;
//	vector<int> res, temp(k, 0), index(k, 0);
//
//	// initialize
//	for (int i = 0; i < k; ++i)
//		temp[i] = nums[i][0];
//
//	while (true) {
//		left1 = *min_element(temp.begin(), temp.end());
//		right1 = *max_element(temp.begin(), temp.end());
//		//cout<<left1<< "**" << right1<<endl;
//
//		if ((right1 - left1) < (right - left) || ((right1 - left1) == (right - left) && left < left1)) {
//			left = left1; right = right1;
//			// cout<<left1<<endl;
//		}
//
//		for (int i = 0; i < k; ++i) {
//			if (temp[i] == left1) {
//				index[i] ++;
//				if (index[i] == nums[i].size()) {
//					res.push_back(left);
//					res.push_back(right);
//					return res;
//				}
//				temp[i] = nums[i][index[i]];
//			}
//		}
//	}
//}
//
// 2
//string minWindow(string s, string t) {
//	vector<int> map(128, 0);
//	for (auto c : t) map[c]++;
//	int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
//	while (end < s.size()) {
//		if (map[s[end++]]-- > 0) counter--;
//		while (counter == 0) {
//			if (end - begin < d) d = end - (head = begin);
//			if (map[s[begin++]]++ == 0) counter++;
//		}
//	}
//	return d == INT_MAX ? "" : s.substr(head, d);
//}
//
//int minSubArrayLen(int s, vector<int>& nums) {
//	int len = INT_MAX, sum = 0, i = 0, j = 0;
//	while (j <= nums.size()) {
//		if (sum < s) {
//			if (j == nums.size())
//				break;
//			sum += nums[j++];
//		}
//		else {
//			len = len < (j - i) ? len : j - i;
//			sum -= nums[i++];
//		}
//	}
//	return len;
//}
//
//bool checkInclusion(string s1, string s2) {
//	vector<int> map(128, 0), temp(128,0);
//	for (auto c : s1) map[c]++;
//	for (int i = 0; i < s1.size()-1; ++i) temp[s2[i]]++;
//
//	for (int i = 0, j = s1.size() - 1; j < s2.size(); ++j) {
//		int k = 0;
//		temp[s2[j]]++;
//		for (k = 40; k < 125; ++k) {
//			if (temp[k] != map[k])
//				break;
//		}
//		if (k == 125) return true;
//		temp[s2[i++]] --;
//	}
//	return false;
//}
//
//vector<int> findAnagrams(string s, string p) {
//	//vector<int> res;
//	//if (s.size() < p.size()) return res;
//	//vector<int> map(128, 0), temp(128, 0);
//	//for (auto c : p) map[c] ++;
//	//for (int i = 0; i < p.size() - 1; ++i) temp[s[i]]++;
//
//	//for (int i = 0, j = p.size() - 1; j < s.size(); ++j) {
//	//	int k = 0;
//	//	temp[s[j]] ++;
//	//	for (k = 41; k < 125; ++k) {
//	//		if (temp[k] != map[k])
//	//			break;
//	//	}
//	//	if (k == 125) res.push_back(i);
//	//	temp[s[i++]] --;
//	//}
//	//return res;
//	vector <int> map(26, 0), temp(26, 0), res;
//	if (s.size() < p.size()) return res;
//
//	for (int i = 0; i < p.size(); ++i)
//	{
//		++map[p[i] - 'a'];
//		++temp[s[i] - 'a'];
//	}
//
//	if (map == temp) res.push_back(0);
//
//	for (int i = p.size(); i < s.size(); ++i)
//	{
//		++temp[s[i] - 'a'];
//		--temp[s[i - p.size()] - 'a'];
//
//		if (map == temp)
//			res.push_back(i-p.size()+1);
//	}
//	return res;
//}
//
//bool isAnagram(string s, string t) {
//	if (s.size() != t.size()) return false;
//	vector<int> m1(26, 0), m2(26, 0);
//	for (int i = 0; i < s.size(); ++i) {
//		++ m1[s[i] - 'a'];
//		-- m1[t[i] - 'a'];
//	}
//	return m1 == m2;
//}

// 2017-8-27


int main() {
	TreeNode * root = new TreeNode(2147483647);
	root->left = new TreeNode(2147483647);
	root->right = new TreeNode(2147483647);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	root->left->right = new TreeNode(100);
	root->left->left = new TreeNode(102);
	// vector<vector<int>> temp{ { 4,10,15,24,26 },{ 0,9,12,20 },{ 5,18,22,30 } };
	// vector<int> res = smallestRange(temp);
	// cout << res[0] << res[1] << endl;
	// vector<int> res = findAnagrams("abab", "ab");
	// cout <<isAnagram("abc","bca")<< endl;


	//    vector<double> rewes = averageOfLevels(root);
	//    for (int i = 0; i < rewes.size(); ++i) {
	//        cout << rewes[i] << endl;
	//    }
	return 0;
}
