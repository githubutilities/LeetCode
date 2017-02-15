// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[left]) {
                ++left;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};

// -----JF-----

class Solution {
  public:
    int findMin(vector<int> &num) {
      if (num.empty()) return 0;
      int res = num[0], l = 0, r = num.size() - 1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (num[0] < num[mid]) l = mid + 1;
        else if (num[0] > num[mid]) {
          res = min(res, num[mid]);
          r = mid - 1;
        } else res = min(res, num[l++]);
      }
      return res;
    }
};
