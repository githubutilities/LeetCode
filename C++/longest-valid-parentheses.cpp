// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestValidParentheses(string s) {
        return max(length(s.begin(), s.end(), '('), length(s.rbegin(), s.rend(), ')'));
    }

private:
    template<typename T>
    int length(T begin, T end, char c) {
        int len = 0, depth = 0;
        T start = begin;
        for (T it = begin; it != end; ++it) {
            if (*it == c) {
                ++depth;
            } else {
                --depth;
                if (depth < 0) {
                    start = next(it);
                    depth = 0;
                } else {
                    if (depth == 0) {
                        len = max(len, static_cast<int>(distance(start, it)) + 1);
                    }
                }
            }
        }
        return len;
    }
};

// -----JF-----

class Solution {
  public:
    int longestValidParentheses(string s) {
      stack<int> stk;
      int res = 0, start = 0;
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == '(') stk.push(i);
        else {
          if (stk.empty()) {
            start = i + 1;
            continue;
          } else stk.pop();
          res = max(res, stk.empty() ? i - start + 1: i - stk.top());
        }
      }
      return res;
    }
};
