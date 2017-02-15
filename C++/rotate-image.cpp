// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                const auto tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1- j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        // Anti-diagonal mirror.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // Horizontal mirror.
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }  
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void rotate(vector<vector<int> > &matrix) {
      const int n = matrix.size();
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n - i; ++ j) {
          swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
        }
      }
      for (int i = 0; i < n / 2; ++ i) {
        for (int j = 0; j < n; ++ j) {
          swap(matrix[i][j], matrix[n - i - 1][j]);
        }
      }
    }
};

//---------

class Solution {
  public:
    void rotate(vector<vector<int> > &matrix) {
      for (int i = 0; i < matrix.size(); ++ i) {
        for (int j = i; j < matrix[i].size() - i - 1; ++ j) {
          int x = i, y = j;
          for (int h = 0, val = matrix[i][j]; h < 4; ++ h) {
            int tx = y, ty = matrix.size() - x - 1, new_val = matrix[tx][ty];
            matrix[tx][ty] = val;
            val = new_val;
            x = tx;
            y = ty;
          }
        }
      }
    }
};
