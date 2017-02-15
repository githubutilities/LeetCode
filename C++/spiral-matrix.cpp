// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        for (int left = 0, right = matrix[0].size() - 1,
                 top = 0, bottom = matrix.size() - 1;
             left <= right && top <= bottom;
             ++left, --right, ++top, --bottom) {

            for (int j = left; j <= right; ++j) {
                res.emplace_back(matrix[top][j]);
            }
            for (int i = top + 1; i < bottom; ++i) {
                res.emplace_back(matrix[i][right]);
            }
            for (int j = right; top < bottom && j >= left; --j) {
                res.emplace_back(matrix[bottom][j]);
            }
            for (int i = bottom - 1; left < right && i > top; --i) {
                res.emplace_back(matrix[i][left]);
            }
        }

        return res;
    }
};

// Time:  O(m * n)
// Space: O(1)
class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        vector<int> res;
        if (m == 0) {
            return res;
        }

        const int n = matrix.front().size();
        enum Action {RIGHT, DOWN, LEFT, UP};
        Action action = RIGHT;
        for (int i = 0, j = 0, begini = 0, beginj = 0, endi = m,
             endj = n, cnt = 0, total = m * n; cnt < total; ++cnt) {

            res.emplace_back(matrix[i][j]);

            switch (action) {
                case RIGHT:
                    if (j + 1 < endj) {
                        ++j;
                    } else {
                        action = DOWN, ++begini, ++i;
                    }
                    break;
                case DOWN:
                    if (i + 1 < endi) {
                        ++i;
                    } else {
                        action = LEFT, --endj, --j;
                    }
                    break;
                case LEFT:
                    if (j - 1 >= beginj) {
                        --j;
                    } else {
                        action = UP, --endi, --i;
                    }
                    break;
                case UP:
                    if (i - 1 >= begini) {
                        --i;
                    } else {
                        action = RIGHT, ++beginj, ++j;
                    }
                    break;
                default:
                    break;
            }
        }
        return res;
    }
};

// -----JF-----

class Solution {
  public:
    bool legal(int x, int y, const vector<vector<int> > &vis) {
      return (x >= 0 && x < vis.size() && y >= 0 && y < vis[x].size() && !vis[x][y]);
    }
    void getNext(int &x, int &y, int &z, const vector<vector<int> > &vis) {
      const int dx[4] = {0, 1, 0, -1};
      const int dy[4] = {1, 0, -1, 0};
      int tx = x + dx[z], ty = y + dy[z];
      if (!legal(tx, ty, vis)) {
        z = (z + 1) % 4;
        x += dx[z];
        y += dy[z];
      } else {
        x = tx;
        y = ty;
      }
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> res;
      if (matrix.size() == 0) return res;
      vector<vector<int> > vis(matrix.size(), vector<int>(matrix[0].size(), 0));
      int x = 0, y = 0, z = 0;
      for (int i = 0; i < matrix.size() * matrix[0].size(); ++ i) {
        res.push_back(matrix[x][y]);
        vis[x][y] = 1;
        getNext(x, y, z, vis);
      }
      return res;
    }
};
