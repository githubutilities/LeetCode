// Time: O(n * 2^n)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> result(1);
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
            }
        }
        return result;
    }
};

// Time: O(n * 2^n)
// Space: O(1)
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> result(1);
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
            }
        }
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    vector<vector<int> > subsets(vector<int> &S) {
      sort(S.begin(), S.end());
      vector<vector<int> > res;
      for (int i = 0; i < (1 << S.size()); ++ i) {
        vector<int> sub;
        for (int j = 0; j < S.size(); ++ j) {
          if (i & (1 << j)) sub.push_back(S[j]);
        }
        res.push_back(sub);
      }
      return res;
    }
};
