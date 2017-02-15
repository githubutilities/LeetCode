// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numeral_map = {{'I',    1}, {'V',   5}, {'X',  10},
                                                {'L',   50}, {'C', 100}, {'D', 500},
                                                {'M', 1000}};
        int decimal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && numeral_map[s[i]] > numeral_map[s[i - 1]]) {
                decimal += numeral_map[s[i]] - 2 * numeral_map[s[i - 1]];
            } else {
                decimal += numeral_map[s[i]];
            }
        }
        return decimal;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int findpos(const char *str, char ch) {
      for (int i = 0; i < strlen(str); ++ i) {
        if (ch == str[i]) return i;
      }
      return -1;
    }
    int romanToInt(string s) {
      const char *letters = "IVXLCDM";
      const int num[] = {1, 5, 10, 50, 100, 500, 1000};
      int res = 0;
      for (int i = 0; i < s.length(); ++ i) {
        bool find = 0;
        int val = num[findpos(letters, s[i])];
        for (int j = i + 1; j < s.length() && !find; ++ j) {
          find |= val < num[findpos(letters, s[j])];
        }
        if (find) res -= val;
        else res += val;
      }
      return res;
    }
};
