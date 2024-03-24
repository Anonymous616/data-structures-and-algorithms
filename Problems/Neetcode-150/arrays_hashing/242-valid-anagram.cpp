// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> sMap;

    for (char c : s) {
      sMap[c]++;
    }

    for (char c : t) {
      if (sMap[c] == 0)
        return false;

      sMap[c]--;
    }

    return true;
  }
};