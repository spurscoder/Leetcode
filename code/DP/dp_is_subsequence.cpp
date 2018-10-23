#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        int index = 0;
        for (int i = 0; i < t_len && index < s_len; ++i) {
            if (t[i] == s[index]) ++ index;
        }
        return index == s_len;
    }
};


int main() {
    Solution sol = Solution();

    cout << sol.isSubsequence("qwe", "qwerwre") << endl;

    return 0;
}