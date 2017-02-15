// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    string multiply(string num1, string num2) {
        const auto char_to_int = [](const char c) { return c - '0'; };
        const auto int_to_char = [](const int i) { return i + '0'; };

        vector<int> n1;
        transform(num1.rbegin(), num1.rend(), back_inserter(n1), char_to_int);
        vector<int> n2;
        transform(num2.rbegin(), num2.rend(), back_inserter(n2), char_to_int);

        vector<int> tmp(n1.size() + n2.size());
        for(int i = 0; i < n1.size(); ++i) {
            for(int j = 0; j < n2.size(); ++j) {
                tmp[i + j] += n1[i] * n2[j];
                tmp[i + j + 1] += tmp[i + j] / 10;
                tmp[i + j] %= 10;
            }
        }
            
        string res;
        transform(find_if(tmp.rbegin(), prev(tmp.rend()),
                         [](const int i) { return i != 0; }),
                  tmp.rend(), back_inserter(res), int_to_char);
        return res;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// Define a new BigInt class solution. 
class Solution2 {
public:
    string multiply(string num1, string num2) {
        return BigInt(num1) * BigInt(num2);
    }

    class BigInt {
    public:
        BigInt(const string& s) {
            transform(s.rbegin(), s.rend(), back_inserter(n_), 
                      [](const char c) { return c - '0'; });
        }
    
        operator string() {
            string s;
            transform(find_if(n_.rbegin(), prev(n_.rend()),
                             [](const int i) { return i != 0; }),
                      n_.rend(), back_inserter(s), 
                      [](const int i) { return i + '0'; });
            return s;
        }
    
        BigInt operator*(const BigInt &rhs) const {
            BigInt res(n_.size() + rhs.size(), 0);
            for(auto i = 0; i < n_.size(); ++i) {
                for(auto j = 0; j < rhs.size(); ++j) {
                    res[i + j] += n_[i] * rhs[j];
                    res[i + j + 1] += res[i + j] / 10;
                    res[i + j] %= 10;
                }
            }
            return res;
        }
    
    private:
        vector<int> n_;
    
        BigInt(int num, int val): n_(num, val) {
        }
    
        // Getter.
        int operator[] (int i) const {
            return n_[i];
        }
    
        // Setter.
        int & operator[] (int i) {
            return n_[i];
        }
    
        size_t size() const {
            return n_.size();
        }
    };
};

// -----JF-----

class Solution {
  public:
    string multiply(string num1, string num2) {
      int op = *num1.begin() == '-' ^ *num2.begin() == '-';
      if (*num1.begin() == '-') num1 = num1.substr(1);
      if (*num2.begin() == '-') num2 = num2.substr(1);
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      const int n = num1.length(), m = num2.length();
      string res(n + m, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          res[i + j] += (num1[i] - '0') * (num2[j] - '0');
          if (res[i + j] >= 10) {
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
          }
        }
      }
      while (res.length() > 1 && *res.rbegin() == 0) res.pop_back();
      for (auto &ch : res) ch += '0';
      if (op > 0) res.push_back('-');
      reverse(res.begin(), res.end());
      return res;
    }
};

//---------

class Solution {
  public:
    string process(string num1, string num2) {
      string res(num1.length() + num2.length(), '0');
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      for (int i = 0; i < num1.length(); ++ i) {
        for (int j = 0; j < num2.length(); ++ j) {
          int l = num1[i] - '0', r = num2[j] - '0';
          int cal = l * r + res[i + j] - '0';
          if (cal >= 10) {
            res[i + j + 1] += cal / 10;
            res[i + j] = '0' + cal % 10;
          } else res[i + j] = cal + '0';
        }
      }
      int len = num1.length() + num2.length();
      while (len > 1 && res[len - 1] == '0') {
        -- len;
        res.pop_back();
      }
      reverse(res.begin(), res.end());
      return res;
    }
    string multiply(string num1, string num2) {
      int flag = 0;
      if (num1[0] == '-') {
        flag ^= 1;
        num1 = num1.substr(1, num1.length() - 1);
      }
      if (num2[0] == '-') {
        flag ^= 1;
        num2 = num2.substr(1, num2.length() - 1);
      }
      string res = process(num1, num2);
      if (flag == 0 || res[0] == '0') return res;
      else return string("-") + res;
    }
};
