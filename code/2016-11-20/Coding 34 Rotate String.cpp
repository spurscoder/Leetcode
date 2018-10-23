/*
Description: Rotate String
Given a string and an offset, rotate string by offset.(rotate from left to right)

Rotate in-place with O(1) extra memory.

*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int len = str.length();
        if (len == 0 || offset == 0) return;
        offset %= len;
        char temp;

        // 1.整体翻转
        for (int i = 0; i < len/2; i++) {
          temp = str[i];
          str[i] = str[len - i - 1];
          str[len - i - 1] = temp;
        }

        // 2.翻转前一部分
        for (int i = 0; i < offset/2; i++) {
          temp = str[i];
          str[i] = str[offset - i - 1];
          str[offset - i - 1] = temp;
        }

        // 3.翻转后一部分**************************************注意序号
        for (int i = offset; i < (len + offset) / 2; i++) {
          temp = str[i];
          str[i] = str[len - i - 1 + offset];
          str[len - i - 1 + offset] = temp;
        }
    }
};
