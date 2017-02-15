// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.cbegin(), digits.cend());
        int carry = 1;
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry == 1) {
            result.emplace(result.begin(), carry);
        }
        return result;  
    }
};
-e 
// -----JF-----

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
      int n = digits.size() - 1, add = 1;
      while (n >= 0) {
        digits[n] += add;
        add = digits[n] / 10;
        digits[n --] %= 10;
      }
      if (add > 0) digits.insert(digits.begin(), 1);
      return digits;
    }
};

//---------

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
      vector<int> res(digits);
      reverse(res.begin(), res.end());
      ++ res[0];
      for (int i = 0; res[i] >= 10; ++ i) {
        if (i + 1 == digits.size()) res.push_back(1);
        else ++ res[i + 1];
        res[i] -= 10;
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
