// https://leetcode.com/problems/can-i-win

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // vector<vector<int> > dp(maxChoosableInteger + 1, vector<int>(desiredTotal + 1, -1)); 
        
        vector<int> dp(desiredTotal + 1, -1); 
        unordered_set<int> unused_coins; 
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            unused_coins.insert(i); 
        }
        return minmax(unused_coins, dp, 0); 
    }
    
    
    bool minmax(unordered_set<int>& unused_coins, vector<int>& dp, int total_sum) {
        
        
        
        
        if (dp[total_sum] != -1) {
            return dp[total_sum] == 1; 
        }
        
        
        for (int i : unused_coins) {
            if (total_sum + i >= dp.size() - 1) {
                return true; 
            }
            unordered_set<int> cpy1 (unused_coins.begin(), unused_coins.end()); 
            cpy1.erase(i); 
            bool canwin = true; 
            for (int j : cpy1) {
                if (total_sum + i + j >= dp.size() - 1) {
                    canwin = false; 
                    break; 
                } else {
                    unordered_set<int> cpy2 (cpy1.begin(), cpy1.end()); 
                    cpy2.erase(j); 
                    if (!minmax(cpy2, dp, total_sum + i + j)) {
                        canwin = false; 
                        break;
                    }
                }
            }
            if (canwin) {
                dp[total_sum] = 1; 
                return true; 
            }
        }
        dp[total_sum] = 0; 
        return false; 
    }
};