// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        vector<int>  dp(n + 1, INT_MAX); 
        
        dp[1] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int c = 1; 
            for (int j = 2*i; j <= n; j += i) {
                c += 1;
                dp[j] = min(dp[j], dp[i] + c); 
                 
            }
        }
        
        return dp[n]; 
        
    }
    
    
};