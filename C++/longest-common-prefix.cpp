// Time:  O(n * k), k is the length of the common prefix
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            for (const auto& str : strs) {
                if (i >= str.length() || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// -----JF-----

class Solution {
  public:
    bool check(const vector<string> &strs, const int &index) {
      if (!strs.size()) return 0;
      for (int i = 0; i < strs.size(); ++ i) {
        if (strs[i].length() < index) return 0;
        if (strs[i][index] != strs[0][index]) return 0;
      }
      return 1;
    }
    string longestCommonPrefix(vector<string> &strs) {
      if (strs.size() == 0) return "";
      int i;
      for (i = 0; check(strs, i); ++ i);
      return strs[0].substr(0, i);
    }
};
