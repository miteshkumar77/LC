// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1); 
        dp[0] = 1; 
        return helper(n, dp); 
    }
    
    int helper(int n, vector<int>& dp) {
        
        if (dp[n] != -1) {
            return dp[n]; 
        }
        int ans = 0; 
        for (int i = 0; i < n; ++i) {
            ans += helper(i, dp) * helper(n - i - 1, dp); 
        }
        dp[n] = ans; 
        return dp[n]; 
    }
};