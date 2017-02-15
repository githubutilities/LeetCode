// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
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
      int l = 0, r = num.size() - 1;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (num[l] > num[mid]) r = mid;
        else if (num[mid] > num[r]) l = mid + 1;
        else return num[l];
      }
      return num[l];
    }
};
