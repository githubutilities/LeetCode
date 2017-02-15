// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        const auto is_space = [](const char c) { return isspace(c); };
        const auto it = find_if_not(s.rbegin(), s.rend(), is_space);
        const auto jt = find_if(it, s.rend(), is_space);
        return distance(it, jt);
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      const string str(s);
      auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
      auto second = find_if_not(first, str.rend(), ::isalpha);
      return distance(first, second);
    }
};

//------

class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      if (s == NULL) return 0;
      string str = "";
      for (int i = strlen(s) - 1; i >= 0; -- i) {
        if (s[i] == ' ') {
          if (str.length() > 0) return str.length();
          str = "";
        } else str += s[i];
      }
      return str.length();
    }
};
