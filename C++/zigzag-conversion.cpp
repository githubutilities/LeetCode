// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        const int step = 2 * numRows - 2;
        string zigzag;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += step) {
                zigzag.push_back(s[j]);
                if (0 < i && i < numRows - 1 &&
                    j + step - 2 * i < s.length()) {
                    zigzag.push_back(s[j + step - 2 * i]);
                }
            }
        }
        return zigzag;
    }
};

// -----JF-----

class Solution {
  public:
    string convert(string s, int nRows) {
      if (nRows == 1) return s;
      string res = "";
      for (int i = 1; i <= nRows; ++ i) {
        int next = 2 * (i - 1);
        for (int j = i - 1; j < s.length(); j += next) {
          res += s[j];
          if (i > 1 && i < nRows) next = 2 * (nRows - 1) - next;
          else next = 2 * (nRows - 1);
        }
      }
      return res;
    }
};
