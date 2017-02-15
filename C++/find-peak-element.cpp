// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) &&
               (mid + 1 == nums.size() || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (!(mid == 0 || nums[mid - 1] < nums[mid])) {
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
    int findPeakElement(const vector<int> &num) {
      const int n = num.size();
      if (n == 1) return 0;
      if (num[0] > num[1]) return 0;
      if (num[n - 1] > num[n - 2]) return n - 1;
      int l = 0, r = n - 1;
      while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (num[m - 1] < num[m] && num[m] > num[m + 1]) return m;
        if (num[m - 1] < num[m]) l = m;
        else r = m;
      }
      return -1;
    }
};
