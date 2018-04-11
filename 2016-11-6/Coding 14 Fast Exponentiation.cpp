/*
问题描述：快速幂
计算a^b % b，其中a，b和n都是32位的整数。
例如 231 % 3 = 2
例如 1001000 % 1000 = 0

思路：分治法
挑战：O(logn)
*/

/*---------分解结果

因为进位对个位不影响，积的取余等于取余的积取余

1.如果b是偶数，我们可以记k = a2 mod c，那么求(k)b/2 mod c就可以了。
2.如果b是奇数，我们也可以记k = a2 mod c，那么求
((k)b/2 mod c × a ) mod c =((k)b/2 mod c * a) mod c 就可以了。

那么我们可以得到以下算法：
算法4：
          int ans = 1;
          a = a % c;
          if(b%2==1)
          ans = (ans * a) mod c; //如果是奇数，要多求一步，可以提前算到ans中
          k = (a*a) % c; //我们取a2而不是a
          for(int i = 1;i<=b/2;i++)
          {
          ans = (ans * k) % c;
          }
          ans = ans % c;

我们可以看到，我们把时间复杂度变成了O(b/2).当然，这样子治标不治本。但我们可以看到，当我们令k = (a * a) mod c时，状态已经发生了变化，我们所要求的最终结果即为(k)b/2 mod c而不是原来的ab mod c，所以我们发现这个过程是可以迭代下去的。当然，对于奇数的情形会多出一项a mod c，所以为了完成迭代，当b是奇数时，我们通过
ans = (ans * a) % c;来弥补多出来的这一项，此时剩余的部分就可以进行迭代了。

形如上式的迭代下去后，当b=0时，所有的因子都已经相乘，算法结束。于是便可以在O（log b）的时间内完成了。于是，有了最终的算法：快速幂算法。
算法5：快速幂算法
          int ans = 1;
          a = a % c;
          while(b>0)
          {
              if(b % 2 == 1)
              ans = (ans * a) % c;
              b = b/2;
              a = (a * a) % c;
          }
将上述的代码结构化，也就是写成函数：
          int PowerMod(int a, int b, int c)
          {
              int ans = 1 % c;
              a = a % c;
              while(b>0)
              {
                  if(b % 2 = = 1)
                    ans = (ans * a) % c;
                  b = b/2;
                  a = (a * a) % c;
              }
              return ans;
          }
本算法的时间复杂度为O（logb），能在几乎所有的程序设计（竞赛）过程中通过，是目前最常用的算法之一。

*/

//对于特殊情况，应该特殊注意
//1. a*a 可能溢出，所以使用长整数 long

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        int ans = 1 % b;
        long t = a % b;
        while (n) {
          if (n & 1)
            ans = ans * t % b;
          n >>= 1;
          t = t * t % b;
        }
        return ans;
    }
};
