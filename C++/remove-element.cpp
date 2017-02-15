// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] != val) {
                ++left;
            } else {
                swap(nums[left],  nums[--right]);
            }
        }
        return right;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
      return distance(A, remove(A, A + n, elem));
    }
};

//---------

class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
      int l, r;
      for (l = 0, r = n - 1; l <= r; ++ l) {
        while (A[r] == elem && l <= r) -- r;
        if (l >= r) break;
        if (A[l] == elem) swap(A[l], A[r]);
      }
      return r + 1;
    }
};
