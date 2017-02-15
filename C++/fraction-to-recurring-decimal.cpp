// Time:  O(logn), where logn is the length of result strings
// Space: O(1)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if ((numerator ^ denominator) >> 31 && numerator != 0) {
            result = "-";
        }

        auto dvd = llabs(numerator);
        auto dvs = llabs(denominator);
        result += to_string(dvd / dvs);
        dvd %= dvs;
        if (dvd > 0) {
            result += ".";
        }
        
        unordered_map<long long, int> lookup;
        while (dvd && !lookup.count(dvd)) {
            lookup[dvd] = result.length();
            dvd *= 10;
            result += to_string(dvd / dvs);
            dvd %= dvs;
        }

        if (lookup.count(dvd)) {
            result.insert(lookup[dvd], "(");
            result.push_back(')');
        }
        return result;
    }
};
-e 
// -----JF-----

class Solution {
  public:
    typedef long long LL;
    string myitoa(LL number) {
      stringstream ss;
      ss << number;
      return ss.str();
    }
    string fractionToDecimal(int numerator, int denominator) {
      if (numerator == 0) return "0";
      string op = "";
      if (numerator < 0 && denominator > 0) op = "-";
      if (numerator > 0 && denominator < 0) op = "-";
      LL p = numerator, q = denominator;
      if (p < 0) p = -p;
      if (q < 0) q = -q;
      string integer, real;
      integer = myitoa(p / q);
      LL mod = p % q;
      if (mod == 0) return op + integer;
      unordered_map<LL, int> pos;
      int index = 0;
      while (mod > 0) {
        if (pos.find(mod) == pos.end()) {
          pos[mod] = index++;
          mod = mod * 10;
          real += myitoa(mod / q);
          mod %= q;
        } else return op + integer + "." + real.substr(0, pos[mod]) + "(" + real.substr(pos[mod]) + ")";
      }
      return op + integer + "." + real;
    }
};
