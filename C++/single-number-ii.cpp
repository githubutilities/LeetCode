// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;

        for (const auto& i : nums) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }

        return one;
    }
};

// -----JF-----

class Solution {
  public:
    int singleNumber(int A[], int n) {
      int one = 0, two = 0;
      for (int i = 0; i < n; ++ i) {
        two |= (one & A[i]);
        one ^= A[i];
        int mod = one & two;
        one &= ~mod;
        two &= ~mod;
      }
      return one;
    }
};
