// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto start = lower_bound(nums.cbegin(), nums.cend(), target);
        const auto end = upper_bound(nums.cbegin(), nums.cend(), target);
        if (start != nums.cend() && *start == target) {
            return {start - nums.cbegin(), end - nums.cbegin() - 1};
        }
        return {-1, -1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);

        if (begin < nums.size() && nums[begin] == target) {
            return {begin, end - 1};
        }

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
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
    vector<int> searchRange(int A[], int n, int target) {
      int l = distance(A, lower_bound(A, A + n, target));
      int r = distance(A, upper_bound(A, A + n, target) - 1);
      return l == n || A[l] != target ? vector<int>({-1, -1}) : vector<int>({l, r});
    }
};

//----------

class Solution {
  public:
    int find(int A[], int n, int target, int flag) {
      int low = 0, upp = n - 1, res = -1;
      while (low <= upp) {
        int mid = (low + upp) >> 1;
        if (A[mid] == target) {
          res = mid;
          if (!flag) upp = mid - 1;
          else low = mid + 1;
        } else if (A[mid] < target) low = mid + 1;
        else upp = mid - 1;
      }
      return res;
    }
    vector<int> searchRange(int A[], int n, int target) {
      vector<int> res;
      res.push_back(find(A, n, target, 0));
      res.push_back(find(A, n, target, 1));
      return res;
    }
};
