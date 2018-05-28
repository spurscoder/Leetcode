#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j+i < n; ++j) {
                int s = 0;
                for (int k = j; k <= j+i; ++k)
                    s += nums[k];
                dp[j][j+i] = max(s - dp[j+1][j+i], s - dp[j][j+i-1]);
            }
        }
        return 2*dp[0][n-1] >= accumulate(nums.begin(), nums.end(), 0) ? true:false;
    }
};

int main(){
    Solution sol = Solution();
    freopen("data.in", "r", stdin);

    vector<int> nums;
    int temp = 0;
    while (cin >> temp)
        nums.push_back(temp);

    cout << sol.PredictTheWinner(nums) << endl;

    return 0;
}