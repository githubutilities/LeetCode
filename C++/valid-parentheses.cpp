// Time:  O(n)		
// Space: O(n)

class Solution {
public:
    bool isValid(string s) {
        const  unordered_map<char, char> symbol_pair = {{')', '('},
                                                        {']', '['},
                                                        {'}', '{'}};
        stack<char> parentheses;
        for (const auto& c: s) {
            const auto& it = symbol_pair.find(c);
            if (it != symbol_pair.cend()) {
                if (parentheses.empty() ||
                    parentheses.top() != it->second) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.emplace(c);
            }
        }
        return parentheses.empty();
    }
};
-e 
// -----JF-----

class Solution {
  public:
    bool isValid(string s) {
      stack<char> stk;
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
        else if (stk.size() > 0) {
          if (s[i] == ')' && stk.top() == '(') stk.pop();
          else if (s[i] == ']' && stk.top() == '[') stk.pop();
          else if (s[i] == '}' && stk.top() == '{') stk.pop();
          else return false;
        } else return false;
      }
      return stk.empty();
    }
};
