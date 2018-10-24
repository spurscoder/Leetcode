/*
Description: Set Matrix Zeroes
Given a m*n matrix, if an element is 0, set its entire row and column to 0. Do it in place

Challenge:      ********
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.     ->use Matrix
A simple improvement uses O(m + n) space, but still not the best solution. ->use Array
Could you devise a constant space solution?                                 ->use itself

*/


class Solution {     // O(1)space
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        const int ROW = matrix.size();
        if (ROW == 0)
          return;
        const int COL = matrix[0].size();
        if (COL == 0)
          return;

        bool R = false;
        for (int i = 0; i < COL; i++)
        {
          if (matrix[0][i] == 0)
          {
              R = true;
              break;
          }
        }
        bool C = false;
        for (int i = 0; i < ROW; i++)
        {
          if (matrix[i][0] == 0)
          {
              C = true;
              break;
          }
        }

        for (int i = 1; i < ROW; i++)
          for (int j = 1; j < COL; j++)
          {
            if (matrix[i][j] == 0)
            {
              matrix[i][0] = 0;
              matrix[0][j] = 0;
            }
          }

        for (int i = 1; i < ROW; i++)
          if (matrix[i][0] == 0)
            for (int j = 1; j < COL; j++)
              matrix[i][j] = 0;
        for (int i = 1; i < COL; i++)
          if (matrix[0][i] == 0)
            for (int j = 1; j < ROW; j++)
              matrix[j][i] = 0;

        if (R)
          fill(begin(matrix[0]), end(matrix[0]), 0);
        if (C)
          for (int i = 0; i < ROW; i++)
            matrix[i][0] = 0;

        return;
    }
};
