// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); ++i) {
            q.emplace(i, 0);
            q.emplace(i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            q.emplace(0, j);
            q.emplace(board.size() - 1, j);
        }

        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            if (board[i][j] == 'O' || board[i][j] == 'V') {
                board[i][j] = 'V';
                const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                        {-1, 0}, {1, 0}};
                for (const auto& d : directions) {
                    const int x = i + d.first, y = j + d.second;
                    if (0 <= x  && x < board.size() &&
                        0 <= y && y < board[0].size() &&
                        board[x][y] == 'O') {
                        board[x][y] = 'V';
                        q.emplace(x, y);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != 'V') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

// -----JF-----

class Solution {
  public:
    void add(int x, int y, vector<vector<int> > &vis, queue<pair<int, int> > &que) {
      if (vis[x][y]) return;
      vis[x][y] = 1;
      que.push(make_pair(x, y));
    }
    void bfs(queue<pair<int, int> > &que, const vector<vector<char> > &board, vector<vector<int> > &vis) {
      const int dx[4] = {-1, 0, 1, 0};
      const int dy[4] = {0, -1, 0, 1};
      while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; ++ i) {
          int tx = x + dx[i], ty = y + dy[i];
          if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) continue;
          if (board[tx][ty] == 'X') continue;
          if (vis[tx][ty]) continue;
          vis[tx][ty] = 1;
          que.push(make_pair(tx, ty));
        }
      }
    }
    void solve(vector<vector<char>> &board) {
      if (board.size() == 0 || board[0].size() == 0) return;
      vector<vector<int> > vis(board.size(), vector<int>(board[0].size(), 0));
      queue<pair<int, int> > que;
      int n = board.size(), m = board[0].size();
      for (int i = 0; i < m; ++ i) {
        if (board[0][i] == 'O') add(0, i, vis, que);
        if (board[n - 1][i] == 'O') add(n - 1, i, vis, que);
      }
      for (int i = 0; i < n; ++ i) {
        if (board[i][0] == 'O') add(i, 0, vis, que);
        if (board[i][m - 1] == 'O') add(i, m - 1, vis, que);
      }
      bfs(que, board, vis);
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
          board[i][j] = vis[i][j] ? 'O' : 'X';
        }
      }
    }
};
