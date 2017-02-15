// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int hold1 = numeric_limits<int>::min();
        int release1 = numeric_limits<int>::min();

        for (const auto& p : prices) {
            hold1 = max(hold1, -p);
            release1 = max(release1, hold1 + p);
        }

        return release1;
    }
};

// -----JF-----

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() == 0) return 0;
      int res = 0, min_val = prices[0];
      for (int i = 1; i < prices.size(); ++ i) {
        res = max(res, prices[i] - min_val);
        min_val = min(min_val, prices[i]);
      }
      return res;
    }
};
