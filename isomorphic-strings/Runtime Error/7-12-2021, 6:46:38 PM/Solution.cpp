// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(26, -1);
        vector<int> pm(26, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (mp[s[i]-'a'] != -1 && mp[s[i]-'a'] != (t[i]-'a')) return false;
            if (pm[t[i]-'a'] != -1 && pm[t[i]-'a'] != (s[i]-'a')) return false;
            mp[s[i]-'a'] = t[i]-'a';
            pm[t[i]-'a'] = s[i]-'a';
        }
        return true;
    }
};