/*
Description: First Bad Version
The Code base version is an integer start from 1 to n . One day, someone committed a
bad version in the code case, so ti caused this version and the following versions
are all falled in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one.
The details interface can be found in the code's annotation part.

Notice:
Please read the annotation in code area to get the correct way to call isBadVersion
in different language. For example, java is SVNRepo.isBadVersion(v)

Tags:
  Binary Search, Facebook
*/


/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1;
        int end = n;
        int mid;
        while(start < end)
        {
          mid = (start + end) / 2;
          if (SVNRepo::isBadVersion(mid))
            end = mid;
          else
            start = mid + 1;
        }
        return start;
    }
};
