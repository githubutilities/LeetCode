// Time:  O(n)
// Space: O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        size_t i = 0;
        vector<Interval> result;
        // Insert intervals appeared before newInterval.
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            result.emplace_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval = {min(newInterval.start, intervals[i].start),
                max(newInterval.end, intervals[i].end)};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
        return result;
    }
};

// -----JF-----

/**
 *  * Definition for an interval.
 *   * struct Interval {
 *    *     int start;
 *     *     int end;
 *      *     Interval() : start(0), end(0) {}
 *       *     Interval(int s, int e) : start(s), end(e) {}
 *        * };
 *         */
class Solution {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval>::iterator iter = intervals.begin();
      vector<Interval> res;
      bool merge = false;
      while (iter != intervals.end() && merge == false) {
        if (newInterval.end < iter->start) {
          res.push_back(newInterval);
          merge = true;
        } else if (newInterval.start > iter->end) res.push_back(*(iter++));
        else {
          newInterval.start = min(iter->start, newInterval.start);
          newInterval.end = max(iter->end, newInterval.end);
          ++iter;
        }
      }
      if (merge == false) res.push_back(newInterval);
      for ( ; iter != intervals.end(); ++iter) res.push_back(*iter);
      return res;
    }
};

//---------

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    bool cmp(const Interval &lhs, const Interval &rhs) {
      return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
    }
    bool match(const Interval &lhs, const Interval &rhs) {
      return rhs.start <= lhs.end;
    }
    void merge(vector<Interval> &res, const Interval &interval) {
      if (res.size() == 0) res.push_back(interval);
      else {
        if (match(res[res.size() - 1], interval)) res[res.size() - 1].end = max(res[res.size() - 1].end, interval.end);
        else res.push_back(interval);
      }
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval> res;
      for (int i = 0, j = 0; i < intervals.size() || j < 1; ) {
        if (i == intervals.size()) {
          merge(res, newInterval);
          ++ j;
        } else if (j == 1) {
          merge(res, intervals[i ++]);
        } else {
          if (cmp(intervals[i], newInterval)) {
            merge(res, intervals[i ++]);
          } else {
            merge(res, newInterval);
            ++ j;
          }
        }
      }
      return res;
    }
};
