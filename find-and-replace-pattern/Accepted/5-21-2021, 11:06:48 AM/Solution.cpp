// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        bool good;
        for(const string& s : words) {
            good = true;
            vector<int> mp1(26, -1);
            vector<int> mp2(26, -1);
            for (int i = 0; i < s.length(); ++i) {
                if (mp1[s[i] - 'a'] != (pattern[i] - 'a') && mp1[s[i] - 'a'] != -1) {
                    good = false;
                    break;
                }
                if (mp2[pattern[i] - 'a'] != (s[i] - 'a') && mp2[pattern[i] - 'a'] != -1) {
                    good = false;
                    break;
                }
                mp1[s[i] - 'a'] = pattern[i] - 'a';
                mp2[pattern[i] - 'a'] = s[i] - 'a';
            }
            if (good) ans.push_back(s);
        }
        return ans;
    }
};