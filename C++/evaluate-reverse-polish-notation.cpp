// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<string> s;
        for (const auto& tok : tokens) {
            if (!is_operator(tok)) {
                s.emplace(tok);
            } else {
                auto&& y = stoi(s.top());
                s.pop();
                auto&& x = stoi(s.top());
                s.pop();
                if (tok[0] == '+') {
                    x += y;
                } else if (tok[0] == '-') {
                    x -= y;
                } else if (tok[0] == '*') {
                    x *= y;
                } else {
                    x /= y;
                }
                s.emplace(to_string(x));
            }
        }
        return stoi(s.top());
    }

private:
    bool is_operator(const string& op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
      stack<int> stk;
      const string op("+-*/");
      for (int i = 0; i < tokens.size(); ++ i) {
        if (op.find(tokens[i]) == string::npos) stk.push(atoi(tokens[i].c_str()));
        else {
          int y = stk.top();
          stk.pop();
          int x = stk.top();
          stk.pop();
          if (tokens[i] == "+") stk.push(x + y);
          if (tokens[i] == "-") stk.push(x - y);
          if (tokens[i] == "*") stk.push(x * y);
          if (tokens[i] == "/") stk.push(x / y);
        }
      }
      return stk.top();
    }
};
