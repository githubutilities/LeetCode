// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int ans = numeric_limits<int>::max();
        int min_diff = numeric_limits<int>::max();

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                int j = i + 1;
                int k = nums.size() - 1;
    
                while (j < k) {  // Time: O(n) for each i.
                    const auto sum = nums[i] + nums[j] + nums[k];
    
                    if (sum > target) {  // Should decrease sum.
                        --k;
                    } else if (sum < target) {  // Should increase sum.
                        ++j;
                    } else {
                        return target;
                    }
    
                    if (abs(sum - target) < min_diff) {
                        min_diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};

// -----JF-----

class Solution {
  public:
    int threeSumClosest(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int res = num[0] + num[1] + num[2];
      for (int i = 0; i < num.size(); ++ i) {
        int l = i + 1, r = num.size() - 1;
        while (l < r) {
          int sum = num[i] + num[l] + num[r];
          if (abs(sum - target) < abs(res - target)) res = sum;
          if (sum < target) ++ l;
          else -- r;
        }
      }
      return res;
    }
};

//------------

class Solution {
  public:
    int threeSumClosest(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int res = num[0] + num[1] + num[2];
      for (int i = 0; i < num.size(); ++ i) {
        for (int l = i + 1, r = num.size() - 1; l < r; ++ l) {
          while (l < r && num[i] + num[l] + num[r] > target) {
            if (abs(res - target) > abs(num[i] + num[l] + num[r] - target)) res = num[i] + num[l] + num[r];
            -- r;
          }
          if (l < r) {
            if (abs(res - target) > abs(num[i] + num[l] + num[r] - target)) res = num[i] + num[l] + num[r];
          }
        }
      }
      return res;
    }
};
