/*
Description: Merge Two Sorted Arrays
Merge two given sorted integer array A and B into a ner sorted integer array

simple

*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int A_length = A.size();
        int B_length = B.size();
        if (A_length == 0)
          return B;
        if (B_length == 0)
          return A;

        vector<int> result;

        int i = 0, j = 0;
        while (i < A_length && j < B_length)
        {
          if (A[i] <= B[j]) {
            result.push_back(A[i]);
            i++;
          } else {
            result.push_back(B[j]);
            ++j;
          }
        }
        if (i == A_length)
          while (j < B_length) {
            result.push_back(B[j]);
            ++j;
          }
        if (j == B_length)
          while (i < A_length) {
            result.push_back(A[i]);
            ++i;
          }

        return result;
    }
};
