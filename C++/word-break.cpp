// Time:  O(n * l^2), l is the max length of the words.
// Space: O(n)

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();

        size_t max_len = 0;
        for (const auto& str: wordDict) {
            max_len = max(max_len, str.length());
        }

        vector<bool> canBreak(n + 1, false);
        canBreak[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= max_len && i - l >= 0; ++l) {
                if (canBreak[i - l] && wordDict.count(s.substr(i - l, l))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }

        return canBreak[n];
    }
};
-e 
// -----JF-----

class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      vector<int> f(s.length() + 1, 0);
      f[0] = 1;
      for (int i = 0; i < s.length(); ++ i) {
        if (!f[i]) continue;
        string current = "";
        for (int j = i; j < s.length(); ++ j) {
          current += s[j];
          if (dict.find(current) != dict.end()) f[j + 1] = 1;
        }
      }
      return f[s.length()] > 0;
    }
};
