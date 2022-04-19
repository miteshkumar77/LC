// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 256> ct{};
        for (char c : t) {
            ++ct[c];
        }
        int n = s.length();
        int missing = t.length();
        int j = 0;
        int ans = INT_MAX;
        int al = 0;
        int ar = 0;
        for (int i = 0; i < n; ++i) {
            if (--ct[s[i]] >= 0) {
                --missing;
            }
            while(j <= i && missing == 0) {
                if (i - j + 1 < ans) {
                    ans = i - j + 1;
                    al = j; ar = i+1;
                }
                if (++ct[s[j++]] > 0) {
                    ++missing;
                }
            }
        }
        return s.substr(al, ar - al);
    }
};