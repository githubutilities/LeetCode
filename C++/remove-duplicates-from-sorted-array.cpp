// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = -1;
        for (const auto& num : nums) {
            if (last == -1 || nums[last] != num) {
                nums[++last] = num;
            }
        }
        return last + 1;
    }
};

// -----JF-----

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      return distance(A, unique(A, A + n));
    }
};

//---------

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      if (n == 0) return 0;
      int l, r;
      for (l = 1, r = 1; r < n; ++ r) {
        if (A[r] != A[l - 1]) A[l ++] = A[r];
      }
      return l;
    }
};

//---------

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      int l, r;
      for (l = 0, r = 0; r < n; ++ r) {
        if (r == 0 || A[r] != A[r - 1]) A[l ++] = A[r];
      }
      return l;
    }
};
