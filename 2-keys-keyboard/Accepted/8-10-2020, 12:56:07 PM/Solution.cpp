// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 
        dp[1] = 0; 
        for (int i = 1; i <= n; ++i) {
            int ctr = 1; 
            for (int j = 2*i; j <= n; j += i) {
                ++ctr; 
                dp[j] = min(dp[j], dp[i] + ctr); 
            }
        }
        
        return dp[n]; 
        
    }
    
    
};