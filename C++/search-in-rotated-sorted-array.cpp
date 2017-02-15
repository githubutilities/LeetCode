// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] >= nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[left] <= nums[mid] && nums[left] <= target && target < nums[mid]) ||
                       (nums[left] > nums[mid] && !(nums[mid] < target && target <= nums[right - 1]))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int search(int A[], int n, int target) {
      int low = 0, upp = n - 1;
      while (low <= upp) {
        int mid = low + (upp - low) / 2;
        if (A[mid] == target) return mid;
        if (low < mid && A[low] < A[mid]) {
          if (A[low] <= target && target <= A[mid - 1]) upp = mid - 1;
          else low = mid + 1;
        } else {
          if (A[mid + 1] <= target && target <= A[upp]) low = mid + 1;
          else upp = mid - 1;
        }
      }
      return -1;
    }
};

//------------------

class Solution {
  public:
    int find(int A[], int target, int lower, int upper) {
      int res = -1;
      while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        if (A[mid] == target) return mid;
        if (A[mid] < target) lower = mid + 1;
        else upper = mid - 1;
      }
      return res;
    }
    int findStart(int A[], int n) {
      int res = 0, lower = 0, upper = n - 1;
      while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        if (A[mid] <= A[n - 1]) {
          res = mid;
          upper = mid - 1;
        } else lower = mid + 1;
      }
      return res;
    }
    int search(int A[], int n, int target) {
      int start = findStart(A, n);
      if (start == 0) return find(A, target, 0, n - 1);
      else {
        int res = find(A, target, 0, start - 1);
        return res == -1 ? find(A, target, start, n - 1) : res;
      }
    }
};
