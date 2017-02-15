// Time:  O(n)
// Space: O(k)

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.length() < t.length()) {
            return "";
        }

        const int ASCII_MAX = 256;
        vector<int> exp_cnt(ASCII_MAX, 0);
        vector<int> cur_cnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for (const auto& c : t) {
            ++exp_cnt[c];
        }

        for (int i = 0; i < s.length(); ++i) {
            if (exp_cnt[s[i]] > 0) {
                ++cur_cnt[s[i]];
                if (cur_cnt[s[i]] <= exp_cnt[s[i]]) {  // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == t.size()) {  // If window meets the requirement.
                while (exp_cnt[s[start]] == 0 ||  // Adjust left bound of window.
                       cur_cnt[s[start]] > exp_cnt[s[start]]) {
                    --cur_cnt[s[start]];
                    ++start;
                }

                if (min_width > i - start + 1) {  // Update minimum window.
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == numeric_limits<int>::max()) {
            return "";
        }

        return s.substr(min_start, min_width);
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void add(char ch, map<char, int> &current, map<char, int> &target, int &reach) {
      ++ current[ch];
      if (target.find(ch) == target.end()) return;
      if (target[ch] == current[ch]) ++ reach;
    }
    void remove(char ch, map<char, int> &current, map<char, int> &target, int &reach) {
      if (target.find(ch) == target.end()) return;
      if (target[ch] == current[ch]) -- reach;
      -- current[ch];
    }
    void update(pair<int, int> &res, int l, int r) {
      if (res.first < 0 || res.second - res.first > r - l) res = make_pair(l, r);
    }
    string minWindow(string S, string T) {
      map<char, int> current, target;
      pair<int, int> res(-1, -1);
      int reach = 0;
      for (int i = 0; i < T.length(); ++ i) ++ target[T[i]];
      for (int l = 0, r = 0; r < S.length(); ++ r) {
        add(S[r], current, target, reach);
        while (l <= r && reach == target.size()) {
          update(res, l, r);
          remove(S[l ++], current, target, reach);
        }
      }
      return res.first == -1 ? "" : string(S.begin() + res.first, S.begin() + res.second + 1);
    }
};
