// Time:  O(n * 2^n)
// Space: O(2^n)

class Solution {
public:
    string countAndSay(int n) {
        string seq{"1"};
        for (int i = 0; i < n - 1; ++i) {
            seq = getNext(seq);
        }
        return seq;
    }

private:
    string getNext(const string& seq) {
        string next_seq;
        for(auto i = seq.cbegin(); i != seq.cend();) {
            auto j = find_if(i, seq.cend(), bind1st(not_equal_to<char>(), *i));
            next_seq.append(to_string(distance(i, j)));
            next_seq.push_back(*i);
            i = j;
        }
        return next_seq;
    }
};

// -----JF-----

class Solution {
  public:
    string getNext(const string &str) {
      stringstream ss;
      for (int i = 0; i < str.length(); ++i) {
        int j = i;
        while (j + 1 < str.length() && str[i] == str[j + 1]) ++j;
        ss << j - i + 1 << str[i];
        i = j;
      }
      return ss.str();
    }
    string countAndSay(int n) {
      string res = "1";
      while (--n) {
        res = getNext(res);
      }
      return res;
    }
};

//---------

class Solution {
  public:
    string getNext(const string &str) {
      string res = "";
      for (int i = 0; i < str.length(); ++ i) {
        int j;
        for (j = i; j < str.length() && str[i] == str[j + 1]; ++ j);
        int tot = j - i + 1, val = str[i] - '0';
        stringstream ss;
        ss << tot * 10 + val;
        res += ss.str();
        i = j;
      }
      return res;
    }
    string countAndSay(int n) {
      string res = "1";
      for (int i = 0; i < n - 1; ++ i) {
        res = getNext(res);
      }
      return res;
    }
};
