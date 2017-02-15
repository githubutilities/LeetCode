// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], cnt = 1;
        for (const auto& i : nums) {
            if (i == ans) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    ans = i;
                    cnt = 1;
                }
            }
        }
        return ans; 
    }
};

// -----JF-----

class Solution {
  public:
    int majorityElement(vector<int> &num) {
      const int n = num.size();
      int res = num[0], count = 1;
      for (int i = 1; i < n; ++i) {
        if (res == num[i]) ++count;
        else {
          --count;
          if (count < 0) {
            count = 1;
            res = num[i];
          }
        }
      }
      return res;
    }
};
