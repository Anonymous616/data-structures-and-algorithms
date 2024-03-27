// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    unordered_map<char, string> key_maps = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1) return {};

        vector<string> result;
        string curr = "";

        dfs(digits, 0, curr, result);

        return result;
    }

    void dfs(string digits, int index, string &curr, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }

        string str = key_maps[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            curr.push_back(str[i]);
            dfs(digits, index + 1, curr, result);
            curr.pop_back();
        }
    }
};
