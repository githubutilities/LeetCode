// Time:  O(n)
// Space: O(n)

class Solution {
public:
    struct Bucket {
        int max = numeric_limits<int>::min();
        int min = numeric_limits<int>::max();
    };

    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        // Init bucket.
        int max_val = *max_element(nums.cbegin(), nums.cend());
        int min_val = *min_element(nums.cbegin(), nums.cend());
        int gap = max(1, static_cast<int>((max_val - min_val) /
                                          (nums.size() - 1)));
        vector<Bucket> buckets((max_val - min_val) / gap + 1);

        // Find the bucket where the n should be put.
        for (const auto& n : nums) {
            // min_val / max_val is in the first / last bucket.
            if (n == max_val || n == min_val) {
                continue;
            }
            int i = (n - min_val) / gap;
            buckets[i].min = min(buckets[i].min, n);
            buckets[i].max = max(buckets[i].max, n);
        }

        // Maximum gap should not be smaller than any gap inside the bucket.
        // i.e. max_gap >= (max_val - min_val) / (count - 1)
        // Thus, only count each bucket gap between the first and the last bucket.
        int max_gap = 0, pre_bucket_max = min_val;
        for (const auto& bucket : buckets) {
            if (bucket.min != numeric_limits<int>::max()) {
                max_gap = max(max_gap, bucket.min - pre_bucket_max);
                pre_bucket_max = bucket.max;
            }
        }
        // Count the last bucket.
        max_gap = max(max_gap, max_val - pre_bucket_max);

        return max_gap;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        // Init bucket.
        int max_val = *max_element(nums.cbegin(), nums.cend());
        int min_val = *min_element(nums.cbegin(), nums.cend());
        int gap = max(1, static_cast<int>((max_val - min_val) /
                                          (nums.size() - 1)));
        map<int, array<int, 2>> bucket;
        using ValueType = enum {MIN, MAX};

        // Find the bucket where the n should be put.
        for (const auto& n : nums) {
            // min_val / max_val is in the first / last bucket.
            if (n == max_val || n == min_val) {
                continue ;    
            }
            int i = (n - min_val) / gap;
            bucket[i][MIN] = min(!bucket[i][MIN] ? numeric_limits<int>::max() : 
                                                   bucket[i][MIN], n);
            bucket[i][MAX] = max(!bucket[i][MAX] ? numeric_limits<int>::min() :
                                                   bucket[i][MAX], n);
        }

        // Count each bucket gap between the first and the last bucket.
        int max_gap = 0, pre_bucket_max = min_val;
        for (auto& kvp : bucket) {
            max_gap = max(max_gap, kvp.second[MIN] - pre_bucket_max);
            pre_bucket_max = (kvp.second)[MAX];
        }
        // Count the last bucket.
        max_gap = max(max_gap, max_val - pre_bucket_max);

        return max_gap;
    }
};

// -----JF-----

class Solution {
  public:
    int maximumGap(vector<int> &num) {
      const int n = num.size();
      if (n < 2) return 0;
      vector<int> max_value(n, INT_MIN), min_value(n, INT_MAX);
      int lower = *min_element(num.begin(), num.end()), upper = *max_element(num.begin(), num.end());
      for (int value : num) {
        int index = (long long)(value - lower) * (n - 1) / (upper - lower);
        max_value[index] = max(max_value[index], value);
        min_value[index] = min(min_value[index], value);
      }
      int max_gap = 0;
      for (int l = 0, r = 1; r < n; ++l) {
        if (max_value[l] == INT_MIN) continue;
        while (r < n && (r <= l || min_value[r] == INT_MAX)) ++r;
        if (l < r && r < n) max_gap = max(max_gap, min_value[r] - max_value[l]);
      }
      return max_gap;
    }
};
