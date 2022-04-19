// https://leetcode.com/problems/one-edit-distance

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int j = 0;
        int set = 0;
        if (s == t) return false;
        if (s.length() + 1 == t.length()) {
            for (int i = 0; i < t.length(); ++i) {
                if (t[i] != s[i]) {
                    if (!set) {
                        ++set;
                        ++i;
                    } else {
                        ++set;
                        break;
                    }
                }
                ++j;
            }
            if (set <= 1) {
                return true;
            }
        }
        
        j = 0;
        set = 0;
        if (s.length() == 1 + t.length()) {
            for (int i = 0; i < t.length(); ++i) {
                if (t[i] != s[i]) {
                    if (!set) {
                        ++set;
                        --i;
                    } else {
                        ++set;
                        break;
                    }
                }
                ++j;
            }
            
            if (set <= 1) {
                return true;
            }
        }
        set = 0;
        j = 0;
        if (s.length() == t.length()) {
            for (int i = 0; i < t.length(); ++i) {
                if (t[i] != s[i]) {
                    if (!set) {
                        ++set;
                    } else {
                        ++set;
                        break;
                    }
                }
                ++j;
            }
            
            if (set <= 1) {
                return true;
            }
        }
        
        return false;
    }
};