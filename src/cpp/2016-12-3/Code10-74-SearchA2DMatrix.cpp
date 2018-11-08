/*
Description:
Write an efficient algorithm that searches for a value in an m*n matrix, This matrix
has the following properties:
  * Integers in each row are sorted from left to right.
  * The first integer of each row is greater than the last integer of the previous row.
*/

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int start = 0, end = m*n - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (matrix[mid/n][mid%n] == target) return true;
      else if (matrix[mid/n][mid%n] > target) end = mid - 1;
      else start = mid + 1;
    }
    return false;
  }
};
