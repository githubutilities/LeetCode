// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            auto prev = result;
            result *= 10;
            result += x % 10;
            if (result / 10 != prev) {
                result = 0;
                break;
            }
            x /= 10;
        }
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    int reverse(int x) {
      int flag = x < 0, res = 0;
      for (x = abs(x); x; x /= 10) res = res * 10 + x % 10;
      return flag ? -res : res;
    }
};
