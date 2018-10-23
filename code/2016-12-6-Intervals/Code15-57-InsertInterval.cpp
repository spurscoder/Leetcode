/*
Given a set of non-overlapping intervals, insert a new intervals into the intervals
(merge if necessary). You may assume that the intervals were initially sorted according
to their start times.

Tags: Array  Sort

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> result;
      auto it = intervals.begin();
      for (; it != intervals.end(); ++it) {
        if (newInterval.end < (*it).start) break;
        else if (newInterval.start > (*it).end) result.push_back(*it);
        else {
          newInterval.start = min(newInterval.start, (*it).start);
          newInterval.end = max(newInterval.end, (*it).end);
        }
      }
      result.push_back(newInterval);
      for (; it != intervals.end(); ++it)
        result.push_back(*it);
      return result;
    }
};
