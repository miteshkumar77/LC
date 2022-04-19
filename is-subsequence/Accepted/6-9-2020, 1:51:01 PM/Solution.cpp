// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0; 
        for (int i = 0; i < t.length(); ++i) {
            if (sp == s.length()) {
                return true; 
            }
            if (t[i] == s[sp]) {
                ++sp; 
            }
        }
        
        if (sp == s.length()) {
            return true; 
        } else {
            return false; 
        }
    }
};