// https://leetcode.com/problems/can-i-win

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if ((maxChoosableInteger + 1)(maxChoosableInteger)/2 < desiredTotal) {
            return false; 
        }
        unordered_set<int> unused_coins; 
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            unused_coins.insert(i); 
        }
        vector<int> dp(desiredTotal + 1, -1); 
        return minimax(unused_coins, dp, 0, desiredTotal); 
    }
    
    
    bool minimax(unordered_set<int>& unused_coins, vector<int>& dp, int total_sum, int& desiredTotal) {
        
        if (dp[total_sum] != -1) {
            return dp[total_sum] == 1; 
        }
        bool canwin = true; 
        for (int i : unused_coins) {
            if (total_sum + i >= desiredTotal) {
                dp[total_sum] = 1; 
                return true; 
            }
            unordered_set<int> cpy (unused_coins.begin(), unused_coins.end()); 
            cpy.erase(i); 
            if (!minimax(cpy, dp, total_sum + i, desiredTotal)){
                dp[total_sum] = 1;
                return true; 
            }
        }
        dp[total_sum] = 0; 
        return false; 
        
    }
};