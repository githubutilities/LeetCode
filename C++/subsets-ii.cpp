// Time:  O(n * 2^n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result(1);
        sort(nums.begin(), nums.end());
        size_t previous_size = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                // Only union non-duplicate element or new union set.
                if (i == 0 || nums[i] != nums[i - 1] || j >= previous_size) {
                    result.emplace_back(result[j]);
                    result.back().emplace_back(nums[i]);
                }
            }
            previous_size = size;
        }
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int getNext(int start, const vector<int> &S) {
      while (start < S.size() - 1 && S[start] == S[start + 1]) ++ start;
      return start + 1;
    }
    void dfs(int start, vector<int> &S, vector<int> &current, vector<vector<int> > &res) {
      if (start == S.size()) {
        res.push_back(current);
        return;
      }
      int next = getNext(start, S);
      dfs(next, S, current, res);
      for (int i = start; i < next; ++ i) {
        current.push_back(S[i]);
        dfs(next, S, current, res);
      }
      for (int i = start; i < next; ++ i) {
        current.pop_back();
      }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      vector<vector<int> > res;
      vector<int> current;
      sort(S.begin(), S.end());
      dfs(0, S, current, res);
      return res;
    }
};
