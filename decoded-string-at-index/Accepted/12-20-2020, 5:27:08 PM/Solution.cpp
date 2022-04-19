// https://leetcode.com/problems/decoded-string-at-index

class Solution {
public:
    
    inline static bool isdigit(char c) {
        return c <= '9' && c >=  '0';
    }
    
    string decodeAtIndex(string s, int K) {
        long long size = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                size *= s[i] - '0';
            } else {
                ++size;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            K %= size;
            if (K == 0 && !isdigit(s[i])) {
                return string(1, s[i]); 
            }
            
            if (isdigit(s[i])) {
                size /= s[i] - '0';
            } else {
                --size;
            }
        }
        
        return "";
    }
};