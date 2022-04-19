// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, INT_MIN);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(max(dp[j], j) * (i - j), dp[i]); 
            }
            
        }
        return dp.back(); 
    }
};