// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            const auto mid = left + (right -left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

// -----JF-----

class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
      return distance(A, lower_bound(A, A + n, target));
    }
};

//---------

class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
      int low = 0, upp = n - 1, res = 0;
      while (low <= upp) {
        int mid = (low + upp) >> 1;
        if (target >= A[mid]) {
          res = mid;
          low = mid + 1;
        } else upp = mid - 1;
      }
      return res + (target > A[res]);
    }
};
