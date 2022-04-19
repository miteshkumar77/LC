// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> sufSums (piles.size()); 
        sufSums[piles.size() - 1] = piles.back(); 
        for (int i = piles.size() - 2; i >= 0; --i) {
            sufSums[i] = piles[i] + sufSums[i + 1]; 
        }
        
        vector<vector<int> > dp (piles.size(), vector<int>(piles.size() + 1, -1)); 
        return helper(piles, 0, 1, sufSums, dp); 
    }
    
    
    
    int helper(vector<int>& piles, int i, int M, vector<int>& sufsums, vector<vector<int>>& dp) {
        if (i >= piles.size()) {
            return 0; 
        }
        
        if (2 * M + i >= piles.size()) {
            return sufsums[i]; 
        }
        
        if (dp[i][M] != -1) {
            return dp[i][M]; 
        }
        int opp_scr = INT_MAX; 
        for (int X = 1; X <= 2 * M; ++X) {
            int res = helper(piles, X + i, max(X, M), sufsums, dp); 
            opp_scr = min(res, opp_scr); 
        }
        dp[i][M] = sufsums[i] - opp_scr; 
        return sufsums[i] - opp_scr; 
    }
    
    
    
};