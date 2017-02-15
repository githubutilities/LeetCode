// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int total = 1;
        for (int i = 1; i <= n; ++i) {
            nums.emplace_back(i);
            total *= i;
        }

        // Cantor Ordering:
        // Construct the k-th permutation with a list of n numbers
        // Idea: group all permutations according to their first number (so n groups, each of
        // (n - 1)! numbers), find the group where the k-th permutation belongs, remove the common
        // first number from the list and append it to the resulting string, and iteratively
        // construct the (((k - 1) % (n - 1)!) + 1)-th permutation with the remaining n-1 numbers
        int group = total;
        stringstream permutation;
        while (n > 0) {
            group /= n;
            int idx = (k - 1) / group;
            permutation << nums[idx];
            nums.erase(nums.begin() + idx);
            k = (k - 1) % group + 1;
            --n;
        }

        return permutation.str();
    }
};
-e 
// -----JF-----

class Solution {
  public:
    string getPermutation(int n, int k) {
      string num(n, '0'), res;
      int base = 1;
      -- k;
      for (int i = 0; i < n; ++ i) num[i] += i + 1;
      for (int i = 2; i < n; ++ i) base *= i;
      for (int i = n - 1; i > 0; k %= base, base /= i, -- i) {
        auto iter = next(num.begin(), k / base);
        res.push_back(*iter);
        num.erase(iter);
      }
      return res + *num.begin();
    }
};

//---------

class Solution {
  public:
    string getPermutation(int n, int k) {
      vector<int> fact(n, 1), use(n, 0);
      string res = "";
      -- k;
      for (int i = 2; i < n; ++ i) fact[i] = fact[i - 1] * i;
      for (int i = 0; i < n; ++ i) {
        int j;
        for (j = 0; k >= fact[n - i - 1] || use[j]; ++ j) {
          if (!use[j]) k -= fact[n - i - 1];
        }
        use[j] = 1;
        res += '0' + j + 1;
      }
      return res;
    }
};
