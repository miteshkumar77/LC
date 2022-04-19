// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
        int maxi = 0;
        int n = s.length();
        auto cmp = [&](int a, int b) -> bool {
            for (int i = 0; a + i < n && b + i < n; ++i) {
                if (s[i + a] > s[i + b]) {
                    return true;
                } else if (s[i + a] < s[i + b]) {
                    return false;   
                }
            }
            return a < b;
        };
        for (int i = 1; i < n; ++i) {
            if (cmp(i, maxi)) {
                maxi = i;
            }
        }
        return s.substr(maxi);
    }
};