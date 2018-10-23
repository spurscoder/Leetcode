/**
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoede_string]. where the encoded_string inside the square
brackets is being repeated exactly k times. note that k is guaranteed to be a positive
integer.
You may assume that the input string is always valid; No extra white spaces, square
brackets are well-formed, etc. Futhermore, you may assume that the original data does
not contain any digits and that digits are only for those repear numbers, k.
For examples, there won't be input like 3a or 2[4].

Examples:
  s = "3[a]2[bc]" return "aaabcbc"
  s = "3[a2[c]]" return "accaccacc"
  s = "2[abc]3[cd]ef" return "abcabcscdcdcdef"
*/

class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    string res;
    while (i < s.length()) {
        res += decodeString(s, i);
        i++;
    }
    return res;
  }
  string decodeString(string s, int &i) {
    string result;
    while (i < s.length() && s[i] != ']') {
      if (!isdigit(s[i]))
        result += s[i++];
      else {
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
          n = n * 10 + s[i++] - '0';

        i++;
        string t = decodeString(s, i);
        i++;

        while (n--)
          result += t;
      }
    }
    return result;
  }
};
