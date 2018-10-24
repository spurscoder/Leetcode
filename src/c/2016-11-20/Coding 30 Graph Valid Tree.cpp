/*
Description: Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges(each edge is a pair of
nodes), write a function to check whether these edges make up a valid Tree

Notice:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

Tags:
Depth First Search, Facebook Zenefits, Union Find（并查集）,
 Breadth First Search, Google

 http://blog.csdn.net/pointbreak1/article/details/48796691
 http://blog.csdn.net/jmspan/article/details/51111048
*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {   //前提条件是<i,j>   i < j
        // Write your code here
        vector<int> root(n, -1);
        for (int i = 0; i < edges.size(); i++) {
          int root1 = find(root, edges[i][0]);
          int root2 = find(root, edges[i][1]);
          if (root1 == root2)
            return false;
          root[root1] = root2;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &root, int e) {
      if (root[e] == -1)
        return e;
      else
        find(root, root[e]);
    }
};
