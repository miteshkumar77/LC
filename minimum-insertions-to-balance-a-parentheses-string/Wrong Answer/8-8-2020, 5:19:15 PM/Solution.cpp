// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string

class Solution {
public:
    int minInsertions(string s) {
        
        
        int ans = 0; 
        int lvl = 0; 
        for (char c : s) {
            if (c == '(') {
                lvl += 2; 
            } else {
                lvl -= 1; 
            }
            
            if (lvl == -2) {
                ++ans; 
                lvl = 0; 
            }
        }
        
        if (lvl == -1) {
            ans += 2; 
        } else {
            ans += lvl; 
        }
        return ans; 
    }
};