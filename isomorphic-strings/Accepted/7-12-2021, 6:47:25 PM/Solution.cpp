// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(256, -1);
        vector<int> pm(256, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (mp[s[i]] != -1 && mp[s[i]] != (t[i])) return false;
            if (pm[t[i]] != -1 && pm[t[i]] != (s[i])) return false;
            mp[s[i]] = t[i];
            pm[t[i]] = s[i];
        }
        return true;
    }
};