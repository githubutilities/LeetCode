// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.length(), n2 = version2.length();
        for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
            int v1 = 0, v2 = 0;
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + version1[i++] - '0';
            }
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + version2[j++] - '0';
            }
            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
        }
        return 0;
    }
};

// -----JF-----

class Solution {
public:
    void stringToVec(const string &version, vector<int> *num) {
        string current = "";
        for (char ch : version) {
            if (ch == '.') {
                num->push_back(atoi(current.c_str()));
                current = "";
            } else current += ch;
        }
        num->push_back(atoi(current.c_str()));
    }
    int compareVersion(string version1, string version2) {
        vector<int> num1, num2;
        stringToVec(version1, &num1);
        stringToVec(version2, &num2);
        auto iter1 = num1.begin(), iter2 = num2.begin();
        while (iter1 != num1.end() && iter2 != num2.end()) {
            if (*iter1 > *iter2) return 1;
            if (*iter1 < *iter2) return -1;
            ++iter1;
            ++iter2;
        }
        int back1 = accumulate(iter1, num1.end(), 0), back2 = accumulate(iter2, num2.end(), 0);
        if (back1 > back2) return 1;
        else if (back1 < back2) return -1;
        else return 0;
    }
};
