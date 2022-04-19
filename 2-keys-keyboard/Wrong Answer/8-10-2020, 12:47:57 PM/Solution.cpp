// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 
        dp[1] = 1; 
        for (int i = 1; i <= n; ++i) {
            for (int j = 2*i; j <= n; j += i) {
                dp[j] = min(dp[j], dp[j - i] + 1); 
            }
        }
        
        return dp[n]; 
        
    }
    
    
};