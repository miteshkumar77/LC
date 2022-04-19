// https://leetcode.com/problems/one-edit-distance

class Solution {
public:
    
    bool es(const string& s, const string& t, int i, int j, int edits) {
        while(true) {
            if (i == s.length() && j == t.length()) {
                return true;
            }
            if (edits < 1) {
                if ((i == s.length() && j != t.length()) || (i != s.length() && j == t.length())) {
                    return false;
                }
                if (s[i] != t[j]) {
                    return false;
                }
                ++i;
                ++j;
            } else {
                if ((i == s.length() || j == t.length()) || s[i] != t[j]) {
                    return es(s, t, i + 1, j, 0) || 
                           es(s, t, i + 1, j + 1, 0) || 
                           es(s, t, i, j + 1, 0); 
                }
                ++i;
                ++j;
            }
        }
        
        return false;
    }
    
    bool isOneEditDistance(string s, string t) {
        if (s == t || s.length() > t.length() + 1 || t.length() > s.length() + 1) return false;
        return es(s, t, 0, 0, 1); 
    }
};