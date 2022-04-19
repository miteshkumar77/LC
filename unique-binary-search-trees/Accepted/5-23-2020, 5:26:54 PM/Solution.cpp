// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1); 
        return helper(n, dp); 
        
    }
    
    int helper(int n, vector<int>& dp) {
        if (dp[n] != -1) {
            return dp[n]; 
        }
        if (n <= 1) {
            dp[n] = 1;
            return dp[n]; 
        } else {
            
            dp[n] = 0; 
            for (int i = 1; i <= n; ++i) {
                dp[n] += helper(n - i, dp) * helper(i - 1, dp); 
            }
            return dp[n]; 
        }
        
    }
};