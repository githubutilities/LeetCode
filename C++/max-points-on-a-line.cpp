// Time:  O(n^2)
// Space: O(n)

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slope_count;
            const auto& start = points[i];
            int same = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                const auto& end = points[j];
                if (start.x == end.x && start.y == end.y) {
                    ++same;
                } else {
                    auto slope = numeric_limits<double>::max();
                    if (start.x - end.x != 0) {
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x);
                    }
                    ++slope_count[slope];
                }
            }

            int current_max = same;
            for (const auto& kvp : slope_count) {
                current_max = max(current_max, kvp.second + same);
            }
            max_points = max(max_points, current_max);
        }

        return max_points;
    }
};
-e 
// -----JF-----

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
  public:
    bool cmp(const Point &lhs, const Point &rhs) {
      if (lhs.x != rhs.x) return lhs.x < rhs.x;
      else return lhs.y < rhs.y;
    }
    pair<int, int> get_pair(int x, int y) {
      if (!x && !y) return make_pair(x, y);
      if (!x) return make_pair(0, y / abs(y));
      if (!y) return make_pair(x / abs(x), 0);
      int d = __gcd(abs(x), abs(y));
      return make_pair(x / d, y / d);
    }
    int maxPoints(vector<Point> &points) {
      if (points.size() == 0) return 0;
      int res = 1;
      for (int i = 0; i < points.size(); ++ i) {
        map<pair<int, int>, int> total;
        int add = 0;
        for (int j = 0; j < points.size(); ++ j) {
          Point l = points[i], r = points[j];
          if (!cmp(l, r) && !cmp(r, l)) {
            ++ add;
            continue;
          }
          if (!cmp(l, r)) swap(l, r);
          ++ total[get_pair(l.x - r.x, l.y - r.y)];
        }
        res = max(res, add);
        for (auto iter = total.begin(); iter != total.end(); ++ iter) {
          res = max(res, iter->second + add);
        }
      }
      return res;
    }
};
