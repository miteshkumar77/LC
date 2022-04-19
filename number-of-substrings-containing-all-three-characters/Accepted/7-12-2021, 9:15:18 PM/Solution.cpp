// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pos(26, -1);
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            pos[s[i]-'a'] = i;
            if (pos['a'-'a'] > -1 && pos['b'-'a'] > -1 && pos['c'-'a'] > -1) {
                ans += 1+(min(pos['a'-'a'], min(pos['b'-'a'], pos['c'-'a'])));
            }
        }
        return ans;
    }
};