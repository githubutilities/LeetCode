// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        nextPermutation(num.begin(), num.end());
    }
    
private:
    template<typename BidiIt>
    bool nextPermutation(BidiIt begin, BidiIt end) {
        const auto rbegin = reverse_iterator<BidiIt>(end);
        const auto rend = reverse_iterator<BidiIt>(begin);
        
        // Find the first element (pivot) which is less than its successor.
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) {
            ++pivot;
        }

        bool is_greater = true;
        if (pivot != rend) {
            // Find the number which is greater than pivot, and swap it with pivot
            auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        } else {
            is_greater = false;
        }
        
        // Make the sequence after pivot non-descending
        reverse(rbegin, pivot);
        
        return is_greater;
    }
};

class Solution2 {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
};
-e 
// -----JF-----

class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      int i, j;
      for (i = num.size() - 2; i >= 0; -- i) {
        if (num[i] < num[i + 1]) break;
      }
      if (i < 0) reverse(num.begin(), num.end());
      else {
        for (j = i; j + 1 < num.size() && num[j + 1] > num[i]; ++ j);
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
      }
    }
};

//---------

class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      int i, j;
      for (i = num.size() - 2; i >= 0; -- i) {
        if (num[i] < num[i + 1]) break;
      }
      if (i < 0) sort(num.begin(), num.end());
      else {
        for (j = i + 1; j < num.size() && num[j] > num[i]; ++ j);
        -- j;
        swap(num[i], num[j]);
        sort(num.begin() + i + 1, num.end());
      }
    }
};
