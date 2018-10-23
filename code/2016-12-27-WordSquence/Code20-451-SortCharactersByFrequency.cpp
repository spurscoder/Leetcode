/*
Given a string, sort it in decreasing order based on the frequency of characters.

Note:
  1. 'Aabb'  ->  'bbAa' 'bbaA'
  2. 'cccaaa' -> 'cccaaa' 'aaaccc'
*/

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> Frequency;
    vector<string> Bucket(s.size()+1, "");
    string result;

    for (char c:s) Frequency[c]++;
    for (auto& it:Frequency) {
      int m = it.second;
      char c = it.first;
      Bucket[m].append(m, c);
    }
    for (int i = s.size()-1; i > 0; i--) {
      if (!Bucket[i].empty())
        result.append(Bucket[i]);
    }
    return result;
  }
};
