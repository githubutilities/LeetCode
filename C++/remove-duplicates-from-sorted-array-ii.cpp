// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const int k = 2; // At most k duplicated.

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right] ||
                (left - k + 1 < 0 || nums[left] != nums[left - k + 1])) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }

        return left + 1; 
    }
};

// -----JF-----

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      if (n <= 2) return n;
      int res = 2;
      for (int i = 2; i < n; ++ i) {
        if (A[i] != A[res - 2]) A[res ++] = A[i];
      }
      return res;
    }
};

//---------------------------------

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
      int l, r, k;
      for (l = 0, r = 0, k = 0; r < n; ++ r) {
        if (l > 0 && A[l - 1] == A[r] && k == 2) continue;
        if (l == 0 || A[l - 1] != A[r]) k = 1;
        else ++ k;
        A[l ++] = A[r];
      }
      return l;
    }
};
