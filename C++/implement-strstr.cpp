// Time:  O(n + k)
// Space: O(k)

// Wiki of KMP algorithm:
// http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        return KMP(haystack, needle);
    }

    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};


// Time:  O(n * k)
// Space: O(k)
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void findNext(char *str, vector<int> &next) {
      int m = strlen(str);
      for (int i = 0, j = -1; i < m; ) {
        if (j == -1 || str[i] == str[j]) {
          ++ i;
          ++ j;
          next[i] = j;
        } else j = next[j];
      }
    }
    char *strStr(char *haystack, char *needle) {
      if (!strcmp(needle, "")) return haystack;
      int n = strlen(haystack), m = strlen(needle);
      vector<int> next(m + 1, -1);
      findNext(needle, next);
      for (int i = 0, j = 0; i < n && j < m; ) {
        if (j == -1 || haystack[i] == needle[j]) {
          ++ i;
          ++ j;
          if (j == m) return haystack + i - j;
        } else j = next[j];
      }
      return NULL;
    }
};
