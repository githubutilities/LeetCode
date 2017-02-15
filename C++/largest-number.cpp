// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort numbers
        sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });

        // combine the numbers
        string max_num;
        for (const auto& i : nums) {
            max_num.append(to_string(i));
        }

        // special case: start with zero (e.g. [0, 0])
        if (!max_num.empty() && max_num[0] == '0')  {
            return "0";
        }

        return max_num;
    }
};

// -----JF-----

class Solution {
  public:
    static bool cmp(const int &l, const int &r) {
      stringstream ss1, ss2;
      ss1 << l << r;
      ss2 << r << l;
      return ss1.str() > ss2.str();
    }
    string largestNumber(vector<int> &num) {
      sort(num.begin(), num.end(), cmp);
      string res = "";
      for (int n : num) {
        if (res == "" && n == 0) continue;
        stringstream ss;
        string str;
        ss << n;
        ss >> str;
        res += str;
      }
      if (res == "") return "0";
      return res;
    }
};
