// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ct(26, 0);
        int t = 3;
        int n = s.length();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (++ct[s[i]-'a'] == 1) {
                --t;
            }
            while(t == 0) {
                if (--ct[s[j++]-'a'] == 0) {
                    ans += j;
                    ++t;
                }
            }
        }
        return ans;
    }
};