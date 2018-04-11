/*
Given a collection of intervals, merge all overlapping intervals.

Tag: Array, Sort
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
   vector<Interval> merge(vector<Interval>& intervals) {
     int size = intervals.size();
     if (size == 0) return {};
     vector<Interval> result;
     sort(intervals.begin(), intervals.end(), function);
     Interval temp;
     temp.start = intervals[0].start;
     int max_end = intervals[0].end;
     for (int i = 0; i < size; i++) {
       if (max_end < intervals[i].start) {
         temp.end = max_end;
         max_end = intervals[i].end;
         result.push_back(temp);
         temp.start = intervals[i].start;
       } else {
         max_end = max(max_end, intervals[i].end);
       }
     }
     temp.end = max_end;
     result.push_back(temp);
     return result;
   }
private:
   static bool function(Interval A, Interval B) {return A.start < B.start; }
};


// 大神写的

vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
