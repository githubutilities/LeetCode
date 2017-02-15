// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void reverseWords(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t begin = 0, end = 0, len = 0;
        while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
            if ((end = s.find(" ", begin)) == string::npos) {
                end = s.length();
            }
            // Reverse each word in the string.
            reverse(s.begin() + begin, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + begin, s.begin() + end, s.begin() + len);
            len += end - begin;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0);
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void reverseWords(string &s) {
      vector<string> arr;
      string current;
      for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == ' ') {
          if (current == "") continue;
          arr.push_back(current);
          current = "";
        } else current += s[i];
      }
      if (current != "") arr.push_back(current);
      s = "";
      for (int i = arr.size() - 1; i >= 0; -- i) {
        s += arr[i];
        if (i > 0) s += " ";
      }
    }
};
