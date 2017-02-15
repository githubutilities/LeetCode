// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        vector<string> tokens(move(split(path, '/')));
        for (const auto& token : tokens) {
            if (token == ".." && !names.empty()) {
                names.pop_back();
            } else if (token != ".." && token != "." && !token.empty()) {
                names.emplace_back(token);
            }
        }
        return string("/").append(join(names, '/'));
    }

private:
    // Split string by delimitor.
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }

    // Join strings with delimitor.
    string join(const vector<string>& names, const char delim) {
        ostringstream ss;
        if (!names.empty()) {
            const string delim_str(1, delim);
            copy(names.cbegin(), prev(names.cend()),
                 ostream_iterator<string>(ss, delim_str.c_str()));
            ss << names.back();
        }
        return ss.str();
    }
};
-e 
// -----JF-----

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for (auto current = path.begin(); current != path.end();) {
            ++current;
            auto next = find(current, path.end(), '/');
            string name(current, next);
            if (name != "." && name.length() > 0) {
                if (name == "..") {
                    if (!dirs.empty()) dirs.pop_back();
                } else dirs.push_back(name);
            }
            current = next;
        }
        if (dirs.empty()) return "/";
        string res = "";
        for (const auto &name : dirs) res += "/" + name;
        return res;
    }
};

//---------

class Solution {
  public:
    void update(vector<string> &res, string &current) {
      if (current != ".") {
        if (current == "..") {
          if (res.size() > 0) res.pop_back();
        } else if (current != "") res.push_back(current);
      }
      current = "";
    }
    string simplifyPath(string path) {
      vector<string> res;
      string current = "";
      for (int i = 0; i <= path.length(); ++ i) {
        if (i == path.length() || path[i] == '/') update(res, current);
        else current += path[i];
      }
      if (res.size() == 0) return "/";
      string res_str = "";
      for (int i = 0; i < res.size(); ++ i) res_str += "/" + res[i];
      return res_str;
    }
};
