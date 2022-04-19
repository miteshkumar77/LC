// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(); int p_len = p.length();
        int p_idx = 0; int s_idx = 0; int star_idx = -1; int match;
        while(s_idx < s_len) {
            if (p_idx < p_len && (p[p_idx] == '?' || s[s_idx] == p[p_idx])) {
                ++p_idx;
                ++s_idx;
            } else if (p_idx < p_len && p[p_idx] == '*') {
                star_idx = ++p_idx;
                match = s_idx;
            } else if (star_idx == -1) {
                return false;
            } else {
                p_idx = star_idx;
                s_idx = ++match;
            }
        }
        
        
        for (int i = p_idx; i < p_len; ++i) {
            if (p[i] != '*') return false;
        }
        return true;
    }
};