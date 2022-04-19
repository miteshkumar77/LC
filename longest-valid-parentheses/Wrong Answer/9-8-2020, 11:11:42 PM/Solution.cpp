// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0; 
        unordered_map<int,int> dp; 
        dp[0] = -1; 
        int lvl = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                --lvl; 
            } else {
                ++lvl; 
            }
            
            if (lvl < 0) {
                lvl = 0; 
                dp = unordered_map<int,int>();
                dp[0] = i; 
                continue;
            }
            
            if (s[i] == ')') {
                ans = max(ans, i - dp[lvl]);
            } else {
                dp.insert(make_pair(lvl, i)); 
            }
        }
        return ans; 
    }
};