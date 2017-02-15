// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(),
                          0, std::bit_xor<int>());
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int singleNumber(int A[], int n) {
      return acuumulate(A, A + n, 0, bit_xor<int>());
    }
};

//---------

class Solution {
  public:
    int singleNumber(int A[], int n) {
      int res = 0;
      for (int i = 0; i < n; ++ i) res ^= A[i];
      return res;
    }
};
