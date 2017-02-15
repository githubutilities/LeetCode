// Time:  O(n * l^2 + n * r), l is the max length of the words, 
//                            r is the number of the results.
// Space: O(n^2)

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();

        size_t max_len = 0;
        for (const auto& str: wordDict) {
            max_len = max(max_len, str.length());
        }

        vector<bool> canBreak(n + 1, false);
        vector<vector<bool>> valid(n, vector<bool>(n, false));
        canBreak[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= max_len && i - l >= 0; ++l) {
                if (canBreak[i - l] && wordDict.count(s.substr(i - l, l))) {
                    valid[i - l][i - 1] = true;
                    canBreak[i] = true;
                }
            }
        }

        vector<string> result, path;
        if (canBreak[n]) {
            wordBreakHelper(s, valid, 0, &path, &result);
        }
        return result;
    }

    
    void wordBreakHelper(const string& s, const vector<vector<bool>>& valid,
                         int start, vector<string> *path, vector<string> *result) {
        if (start == s.length()) {
            string tmp;
            for (const auto& str : *path) {
                tmp += str;
                tmp += " ";
            }
            tmp.pop_back();
            result->emplace_back(move(tmp));
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (valid[start][i]) {
                path->emplace_back(s.substr(start, i + 1 - start));
                wordBreakHelper(s, valid, i + 1, path, result);
                path->pop_back();
            }
        }
    }
};

// -----JF-----

class Solution {
  public:
    void getPrev(const int &length, const string &s, const unordered_set<string> &dict, vector<int> &dp, vector<vector<int> > &pre) {
      dp[0] = 1;
      for (int i = 0; i < length; ++i) {
        if (dp[i] == 0) continue;
        string current = "";
        for (int j = i; j < length; ++j) {
          current += s[j];
          if (dict.find(current) != dict.end()) dp[j + 1] = pre[j + 1][i] = 1;
        }
      }
    }
    void genPath(const int &current, const string &s, const vector<vector<int> > &pre, vector<string> &res, vector<string> &path) {
      if (current == 0) {
        string line = "";
        for (auto iter = path.rbegin(); iter != path.rend(); ++iter) {
          line += *iter + " ";
        }
        line.pop_back();
        res.push_back(line);
      } else {
        for (int i = 0; i < current; ++i) {
          if (pre[current][i] > 0) {
            path.push_back(s.substr(i, current - i));
            genPath(i, s, pre, res, path);
            path.pop_back();
          }
        }
      }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      const int n = s.length();
      vector<int> dp(n + 1, 0);
      vector<vector<int> > pre(n + 1, vector<int>(n + 1, 0));
      getPrev(n, s, dict, dp, pre);
      vector<string> res, path;
      genPath(n, s, pre, res, path);
      return res;
    }
};

//---------

class Solution {
  public:
    vector<string> dfs(int start, string &str, map<int, vector<string> > &ans, unordered_set<string> &dict) {
      if (ans.find(start) != ans.end()) return ans[start];
      vector<string> res;
      string current = "";
      for (int i = start; i < str.length(); ++ i) {
        current += str[i];
        if (dict.find(current) == dict.end()) continue;
        if (i < str.length() - 1) {
          vector<string> suffix = dfs(i + 1, str, ans, dict);
          for (int j = 0; j < suffix.size(); ++ j) {
            res.push_back(current + " " + suffix[j]);
          }
        } else res.push_back(current);
      }
      ans[start] = res;
      return res;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      map<int, vector<string> > res;
      return dfs(0, s, res, dict);
    }
};
