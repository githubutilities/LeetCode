// Time:  (2^n)
// Space: O(1)

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = result.size() - 1; j >= 0; --j) {
                result.emplace_back(1 << i | result[j]);
            }
        }
        return result;
    }
};

// Time:  (2^n)
// Space: O(1)
// Proof of closed form formula could be found here:
// http://math.stackexchange.com/questions/425894/proof-of-closed-form-formula-to-convert-a-binary-number-to-its-gray-code
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < 1 << n; ++i) {
            result.emplace_back(i >> 1 ^ i);
        }
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> res(1 << n, 0);
      for (int len = 4, mask = 1; len <= (1 << (n + 1)); len <<= 1, mask <<= 1) {
        for (int i = 0; i < (1 << n); i += len) {
          for (int j = len / 4; j < len / 4 * 3 && i + j < (1 << n); ++ j) {
            res[i + j] += mask;
          }
        }
      }
      return res;
    }
};
