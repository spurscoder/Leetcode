/*
Description: The set [1,2,3,..,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence(ie, for n = 3):
...
...
...
Given n and k, return kth permutation sequense.
Note : Given n will be between 1 and 9 inclusive.

*/

class Solution {
public:
  string getPermutation(int n, int k) {
          vector<int> nums(n);
          int pCount = 1;
          for(int i = 0 ; i < n; ++i) {
              nums[i] = i + 1;
              pCount *= (i + 1);
          }

          k--;
          string res = "";
          for(int i = 0 ; i < n; i++) {
              pCount = pCount/(n-i);
              int selected = k / pCount;
              res += ('0' + nums[selected]);

              for(int j = selected; j < n-i-1; j++)
                  nums[j] = nums[j+1];
              k = k % pCount;
          }
          return res;
      }
};

// ********************************************************************

class Solution {
public:
  string getPermutation(int n, int k) {
      int i,j,f=1;
      // left part of s is partially formed permutation, right part is the leftover chars.
      string s(n,'0');
      for(i=1;i<=n;i++){
          f*=i;
          s[i-1]+=i; // make s become 1234...n
      }
      for(i=0,k--;i<n;i++){
          f/=n-i;
          j=i+k/f; // calculate index of char to put at s[i]
          char c=s[j];
          // remove c by shifting to cover up (adjust the right part).
          for(;j>i;j--)
              s[j]=s[j-1];
          k%=f;
          s[i]=c;
      }
      return s;
  }
};
