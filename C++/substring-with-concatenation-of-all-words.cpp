// Time:  O((m - n * k) * n * k) ~ O(m * n * k), m is the length of the string,
//                                               n is the size of the dictionary,
//                                               k is the length of each word
// Space: O(n * k)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto word_length = words.front().length();
        const auto cat_length = word_length * words.size();
        vector<int> result;

        if (s.length() < cat_length) {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (const auto & word : words) {
            ++wordCount[word];
        }

        for (auto it = s.begin(); it != prev(s.end(), cat_length - 1); ++it) {
            unordered_map<string, int> unused(wordCount);
            for (auto jt = it; jt != next(it, cat_length); jt += word_length) {
                auto pos = unused.find(string(jt, next(jt, word_length)));
                if (pos == unused.end()) {
                    break;
                }
                if (--pos->second == 0) {
                    unused.erase(pos);
                }
            }
            if (unused.empty()) {
                result.emplace_back(distance(s.begin(), it));
            }
        }
        return result;
    }
};

// -----JF-----

class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      unordered_map<string, int> dict;
      for (int i = 0; i < L.size(); ++ i) ++ dict[L[i]];
      vector<int> res;
      int len = L[0].length();
      for (int start = 0; start < len; ++ start) {
        unordered_map<string, int> current;
        int l = start, r = l, reach = 0;
        while (true) {
          if (r + len > S.length()) break;
          string word = S.substr(r, len);
          r += len;
          if (dict.find(word) == dict.end()) {
            reach = 0;
            current.clear();
            l = r;
          } else {
            ++ current[word];
            if (current[word] == dict[word]) ++ reach;
            else {
              while (current[word] > dict[word]) {
                string rword = S.substr(l, len);
                if (current[rword] == dict[rword]) -- reach;
                -- current[rword];
                l += len;
              }
            }
            if (reach == dict.size()) res.push_back(l);
          }
        }
      }
      return res;
    }
};

//---------

class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      unordered_map<string, int> dict;
      for (int i = 0; i < L.size(); ++ i) ++ dict[L[i]];
      vector<int> res;
      int len = L[0].length();
      for (int i = 0; i + L.size() * len <= S.length(); ++ i) {
        unordered_map<string, int> current;
        bool flag = true;
        for (int j = 0; j < L.size() * len && flag; j += len) {
          string word = S.substr(i + j, len);
          if (dict.find(word) == dict.end()) flag = false;
          if (current[word] == dict[word]) flag = false;
          ++ current[word];
        }
        if (flag) res.push_back(i);
      }
      return res;
    }
};
