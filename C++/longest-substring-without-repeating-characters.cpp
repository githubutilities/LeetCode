// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Record the last occurrence of each char.
        unordered_map<char, size_t> last_occurrence;
        size_t starting_idx = 0, ans = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            auto it(last_occurrence.find(s[i]));
            if (it == last_occurrence.cend()) {
                last_occurrence.emplace_hint(it, s[i], i);
            } else {  // s[i] appeared before. Check its validity.
                if (it->second >= starting_idx) {
                    ans = max(ans, i - starting_idx);
                    starting_idx = it->second + 1;
                }
                it->second = i;
            }
        }
        ans = max(ans, s.size() - starting_idx);
        return ans;
    }
};

// -----JF-----

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      const int kAsciiMax = 256;
      const int n = s.length();
      vector<int> last(kAsciiMax, -1);
      int res = 0, start = 0;
      for (int i = 0; i < n; ++i) {
        if (last[int(s[i])] >= start) {
          res = max(res, i - start);
          start = last[int(s[i])] + 1;
        }
        last[int(s[i])] = i;
      }
      res = max(res, n - start);
      return res;
    }
};

//---------

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> count;
      int res = 0;
      for (int l = 0, r = 0; r < s.length(); ++ r) {
        ++ count[s[r]];
        while (count[s[r]] > 1 && l < r) {
          -- count[s[l]];
          ++ l;
        }
        res = max(res, r - l + 1);
      }
      return res;
    }
};
