// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int i = 0, j = height.size() - 1;
        int left_height = height[0];
        int right_height = height[height.size() - 1];
        int trap = 0;

        while (i < j) {
            if (left_height < right_height) {
                ++i;
                // Fill in the gap.
                trap += max(0, left_height - height[i]);
                // Update current max height from left.
                left_height = max(left_height, height[i]);
            }
            else {
                --j;
                // Fill in the gap.
                trap += max(0, right_height - height[j]);
                // Update current max height from right.
                right_height = max(right_height, height[j]);
            }
        }

        return trap;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int trap(int A[], int n) {
      int max_height_index = 0, res = 0;
      for (int i = 1; i < n; ++ i) {
        if (A[max_height_index] < A[i]) max_height_index = i;
      }
      for (int i = 0, cur = 0; i < max_height_index; ++ i) {
        if (cur < A[i]) cur = A[i];
        else res += cur - A[i];
      }
      for (int i = n - 1, cur = 0; i > max_height_index; -- i) {
        if (cur < A[i]) cur = A[i];
        else res += cur - A[i];
      }
      return res;
    }
};

//------

class Solution {
  public:
    int trap(int A[], int n) {
      vector<int> left(n, 0), right(n, 0);
      for (int i = 1; i < n; ++ i) {
        left[i] = max(left[i - 1], A[i - 1]);
        right[n - i - 1] = max(right[n - i], A[n - i]);
      }
      int res = 0;
      for (int i = 0; i < n; ++ i) res += max(0, min(left[i], right[i]) - A[i]);
      return res;
    }
};

//---------

class Solution {
  public:
    int trap(int A[], int n) {
      vector<int> ls(n, 0), rs(n, 0);
      for (int i = 0; i < n; ++ i) {
        ls[i] = !i ? 0 : max(ls[i - 1], A[i - 1]);
      }
      for (int i = n - 1; i >= 0; -- i) {
        rs[i] = i == n - 1 ? 0 : max(rs[i + 1], A[i + 1]);
      }
      int res = 0;
      for (int i = 0; i < n; ++ i) res += max(0, min(ls[i], rs[i]) - A[i]);
      return res;
    }
};
