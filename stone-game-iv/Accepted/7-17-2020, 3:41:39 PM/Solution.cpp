// https://leetcode.com/problems/stone-game-iv

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return minimax(n, dp); 
    }
    
    
    
    
    bool minimax(int n, vector<int>& dp) {
        if (n == 0) {
            return false; 
        }
        
        if (dp[n] != -1) {
            return dp[n] == 1;
        }
        
        
        for (int i = 1; i * i <= n; ++i) {
            if (!minimax(n - i * i, dp)) {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = -1;
        return false; 
    }
};