/*
问题描述：木材加工
有一些原木，现在想把这些木头切割成一些长度相同的小段木头，
需要得到的小段的数目至少为 k。当然，我们希望得到的小段越长越好，
你需要计算能够得到的小段木头的最大长度。

注意事项：
木头长度的单位是厘米。原木的长度都是正整数，
我们要求切割得到的小段木头的长度也要求是整数。
无法切出要求至少 k 段的,则返回 0 即可。

挑战：
O(n log Len), Len为 n 段原木中最大的长度

标签：
二分法
*/

/**********************************************
for(auto element : MyArray)
遍历MyArray中的元素

max = Math.max(X,Y);
取最大值
*/
class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.size() == 0)
          return 0;
        long long sum = 0;
        for (auto x:L)
          sum += x;
        if (sum < k)
          return 0;
        long long len = *max_element(L.begin(),L.end());
        long long l = 1, r = len;
        while (l < r)
        {
          long long mid = (l + r + 1) / 2;    //O(log(len))
          if (judge(L, k, mid))               //O(n)
            l = mid;
          else
            r = mid - 1;
        }
        return l;
    }

    bool judge(const vector<int> L,const int k,const int mid)
    {
      long long cnt = 0;
      for (auto x:L)
        cnt += x/mid;
      return cnt >= k;
    }
};


/**
此算法确实是nlog(len)时间复杂度

*/
