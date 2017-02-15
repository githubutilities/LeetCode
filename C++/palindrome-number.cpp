// Time:  O(logx) = O(1)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        int reversed = 0;
        while (temp != 0) {
            reversed = reversed * 10 + temp % 10;
            temp = temp / 10;
        }
        return reversed == x;
    }
};

// Time:  O(logx) = O(1)
// Space: O(1)
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        int divisor = 1;
        while (x / divisor >= 10) {
            divisor *= 10;
        }

        for (; x > 0; x = (x % divisor) / 10, divisor /= 100) {
            int left = x / divisor;
            int right = x % 10;
            if (left != right) {
                return false;
            }
        }

        return true;
    }
};

// -----JF-----

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int power = 1;
      while (power <= x / 10) power *= 10;
      while (x > 0) {
        int i = x / power, j = x % 10;
        if (i != j) return false;
        x = x % power / 10;
        power /= 100;
      }
      return true;
    }
};

//---------

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int val = x, y = 0, bak = val;
      for ( ; val; val /= 10) y = y * 10 + val % 10;
      return bak == y;
    }
};
