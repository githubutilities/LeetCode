// Time:  O(m * n)
// Space: O(n)

// Ascending stack solution.
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int res = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            res = max(res, largestRectangleArea(height));
        }

        return res;
    }

private:
    int largestRectangleArea(const vector<int> &height) {
        stack<int> increasing_height;
        int max_area = 0;

        for (int i = 0; i <= height.size();) {
            if (increasing_height.empty() ||
                (i < height.size() && height[i] > height[increasing_height.top()])) {
                increasing_height.emplace(i);
                ++i;
            } else {
                auto h = height[increasing_height.top()];
                increasing_height.pop();
                auto left = increasing_height.empty() ? -1 : increasing_height.top();
                max_area = max(max_area, h * (i - left - 1));
            }
        }

        return max_area;
    }
};

// Time:  O(m * n)
// Space: O(n)
// DP solution.
class Solution2 {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        const int m = matrix.size();
        const int n = matrix.front().size();
        int res = 0;
        vector<int> H(n, 0);  // Height of all ones rectangle include matrix[i][j].
        vector<int> L(n, 0);  // Left closed bound of all ones rectangle include matrix[i][j].
        vector<int> R(n, n);  // Right open bound of all ones rectangle include matrix[i][j].

        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];  // Update height.
                    L[j] = max(L[j], left); // Update left bound.
                } else {
                    left = j + 1;
                    H[j] = L[j] = 0;
                    R[j] = n;
                }
            }

            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);  // Update right bound.
                    res = max(res, H[j] * (R[j] - L[j]));
                } else {
                    right = j;
                }
            }
        }

        return res;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int maximalRectangle(vector<vector<char> > &matrix) {
      if (matrix.empty()) return 0;
      const int n = matrix.size();
      const int m = matrix[0].size();
      vector<int> left(m, 0), right(m, m - 1), height(m, 0);
      int area = 0;
      for (int i = 0; i < n; ++i) {
        int l = 0, r = m - 1;
        for (int j = 0; j < m; ++j) {
          if (matrix[i][j] == '1') {
            ++height[j];
            left[j] = max(left[j], l);
          } else {
            height[j] = left[j] = 0;
            right[j] = m - 1;
            l = j + 1;
          }
        }
        for (int j = m - 1; j >= 0; --j) {
          if (matrix[i][j] == '1') {
            right[j] = min(right[j], r);
            area = max(area, height[j] * (right[j] - left[j] + 1));
          } else r = j - 1;
        }
      }
      return area;
    }
};

//---------

class Solution {
  public:
    void calLength(vector<int> &arr, vector<int> &res) {
      stack<int> stk;
      for (int i = 0; i < arr.size(); ++ i) {
        while (!stk.empty()) {
          int val = arr[stk.top()];
          if (val >= arr[i]) stk.pop();
          else break;
        }
        if (stk.empty()) res[i] = i + 1;
        else res[i] = i - stk.top();
        stk.push(i);
      }
    }
    int process(vector<int> &arr) {
      vector<int> l(arr.size(), 0), r(arr.size());
      calLength(arr, l);
      reverse(arr.begin(), arr.end());
      calLength(arr, r);
      int res = 0;
      for (int i = 0; i < arr.size(); ++ i) {
        res = max(res, (l[arr.size() - i - 1] + r[i] - 1) * arr[i]);
      }
      return res;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
      if (matrix.size() == 0) return 0;
      vector<vector<int> > s(matrix.size(), vector<int>(matrix[0].size(), 0));
      for (int i = 0; i < matrix.size(); ++ i) {
        for (int j = 0; j < matrix[i].size(); ++ j) {
          if (matrix[i][j] == '0') s[i][j] = 0;
          else {
            if (i > 0) s[i][j] = s[i - 1][j] + 1;
            else s[i][j] = 1;
          }
        }
      }
      int res = 0;
      for (int i = 0; i < matrix.size(); ++ i) {
        res = max(res, process(s[i]));
      }
      return res;
    }
};
