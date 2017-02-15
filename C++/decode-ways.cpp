// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int prev = 0; // f[n - 2]
        int cur = 1;  // f[n - 1]

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                cur = 0; // f[n - 1] = 0
            }
            if (i == 0 ||
                !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                prev = 0; // f[n - 2] = 0
            }

            int tmp = cur;
            cur += prev; // f[n] = f[n - 1] + f[n - 2]
            prev = tmp;
        }

        return cur;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int numDecodings(string s) const {
      if (s.empty()) return 0;
      vector<int> f(s.length() + 1);
      f[0] = 1;
      f[1] = (s[0] > '0');
      for (int i = 2; i < f.length(); ++ i) {  // i < f.length()
        int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        f[i] = f[i - 1] * (s[i - 1] > '0') + f[i - 2] * (val >= 10 && val <= 26);
      }
      return f[f.length() - 1];
    }
};
