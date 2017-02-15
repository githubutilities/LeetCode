// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (const auto& c : s) {
            number *= 26;
            number += c  - 'A' + 1;
        }
        return number;
    }
};

// -----JF-----

class Solution {
  public:
    int trailingZeroes(int n) {
      const int kBase = 5;
      int res = 0;
      for (long long current = kBase; n >= current; current *= kBase) res += n / current;
      return res;
    }
};
