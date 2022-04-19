// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0; 
        for (int i = 0; i < s.size(); ++i) {
            int l = i; 
            int r = i; 
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                ++r;
                --l;
                ++ans; 
            }
        }
        
        for (int i = 1; i < s.size(); ++i) {
            int l = i - 1; 
            int r = i; 
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                ++r; 
                --l;
                ++ans;
            }
        }
        
        return ans; 
    }
};