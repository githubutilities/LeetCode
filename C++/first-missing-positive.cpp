// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        bucketSort(&nums);
        for (; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }

private:
    void bucketSort(vector<int> *nums) {
        int i = 0;
        while (i < nums->size()) {
            if ((*nums)[i] > 0 && (*nums)[i] <= nums->size() &&
                (*nums)[i] != (*nums)[(*nums)[i] - 1]) {
                swap((*nums)[i], (*nums)[(*nums)[i] - 1]);
            } else {
                ++i;
            }
        }
    }
};

// -----JF-----

class Solution {
  public:
    int firstMissingPositive(int A[], int n) {
      for (int i = 0; i < n; ++ i) {
        if (A[i] <= 0 || A[i] > n || A[i] == i + 1) continue;
        while (A[A[i] - 1] != A[i]) {
          swap(A[i], A[A[i] - 1]);
          if (A[i] <= 0 || A[i] > n) break;
        }
      }
      for (int i = 0; i < n; ++ i) {
        if (A[i] != i + 1) return i + 1;
      }
      return n + 1;
    }
};
