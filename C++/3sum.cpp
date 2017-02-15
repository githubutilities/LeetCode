// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {  // Should decrease sum.
                            --k;
                        } else if (sum < target) {  // Should increase sum.
                            ++j;
                        } else {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
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
    vector<vector<int> > threeSum(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      for (int i = 0; i < num.size(); ++ i) {
        for (int l = i + 1, r = num.size() - 1; l < r; ++ l) {
          while (num[i] + num[l] + num[r] > 0 && l < r) -- r;
          if (l < r && num[i] + num[l] + num[r] == 0) {
            res.push_back({num[i], num[l], num[r]});
          }
        }
      }
      sort(res.begin(), res.end());
      res.erase(unique(res.begin(), res.end()), res.end());
      return res;
    }
};

//--------------

class Solution {
  public:
    vector<vector<int> > threeSum(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      for (int i = 0; i < num.size(); ++ i) {
        if (i > 0 && num[i] == num[i - 1]) continue;
        for (int l = i + 1, r = num.size() - 1; l < r; ++ l) {
          if (l - 1 > i && num[l] == num[l - 1]) continue;
          while (num[i] + num[l] + num[r] > 0 && l < r) -- r;
          if (l < r && num[i] + num[l] + num[r] == 0) {
            res.push_back({num[i], num[l], num[r]});
          }
        }
      }
      return res;
    }
};
