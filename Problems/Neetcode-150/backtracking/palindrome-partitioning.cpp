class Solution {
public:
  vector<vector<string>> result;

  bool isPalindrome(string word) {
    int n = word.size() - 1;
    for (int i = 0; i <= n; i++) {
      if (word[i] != word[n - i]) {
        return false;
      }
    }

    return true;
  }

  void dfs(vector<string> &part, string s, int sIndex) {
    if (sIndex >= s.size()) {
      result.push_back(part);
      return;
    }

    for (int i = sIndex; i < s.size(); i++) {
      string sub = s.substr(sIndex, i - sIndex + 1);
      if (isPalindrome(sub)) {
        part.push_back(sub);
        dfs(part, s, i + 1);
        part.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<string> part;
    dfs(part, s, 0);

    return result;
  }
};