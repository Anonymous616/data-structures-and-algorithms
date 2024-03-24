// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<map<char, int>, vector<string>> groups;

    for (int i = 0; i < strs.size(); i++) {
      map<char, int> sMap;

      for (char c : strs[i]) {
        sMap[c]++;
      }

      if (groups.count(sMap)) {
        groups[sMap].push_back(strs[i]);
      } else {
        groups[sMap] = vector<string>{strs[i]};
      }
    }

    vector<vector<string>> result;

    for (pair<map<char, int>, vector<string>> p : groups) {
      result.push_back(p.second);
    }

    return result;
  }
};