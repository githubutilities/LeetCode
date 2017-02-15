// Time:  O(n)
// Space: O(1)

// Tri-Partition solution.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int target = 1;
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
            if (nums[j] < target) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] > target) {
                swap(nums[j], nums[n--]);
            } else {
                ++j;
            }
        }
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void sortColors(int A[], int n) {
      int total[3] = {0, 0, 0};
      for (int i = 0; i < n; ++ i) ++ total[A[i]];
      for (int i = 0, j = 0; i < 3; ++ i) {
        for (int h = 0; h < total[i]; ++ h, ++ j) A[j] = i;
      }
    }
};
