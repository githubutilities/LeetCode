// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string intToRoman(int num) {
        const vector<int> nums{1000, 900, 500, 400, 100, 90,
                               50, 40, 10, 9, 5, 4, 1};
        const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L",
                                    "XL", "X", "IX", "V", "IV", "I"};

        string result;
        int i = 0;
        while (num > 0) {
            int times = num / nums[i];
            while (times--) {
                num -= nums[i];
                result.append(romans[i]);
            }
            ++i;
        }        
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    string intToRoman(int num) {
      const char *letters = "IVXLCDM";
      string res = "";
      int arr[4];
      for (int i = 0; i < 4; ++ i) {
        arr[i] = num % 10;
        num /= 10;
      }
      for (int i = 3, h = 6; i >= 0; -- i, h -= 2) {
        if (arr[i] <= 3) {
          for (int j = 0; j < arr[i]; ++ j) res += letters[h];
        } else if (arr[i] < 9) {
          for (int k = 0; k < 5 - arr[i]; ++ k) res += letters[h];
          res += letters[h + 1];
          for (int k = 0; k < arr[i] - 5; ++ k) res += letters[h];
        } else {
          res += letters[h];
          res += letters[h + 2];
        }
      }
      return res;
    }
};
