// https://leetcode.com/problems/last-stone-weight-ii

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum = 0; 
        for (int stone: stones) {
            sum += stone; 
        }
        
        int tmp = sum; 
        sum = sum / 2; 
        
        vector<vector<bool> > dp(stones.size() + 1, vector<bool>(sum + 1, false));
        
        for (int i = 0; i <= stones.size(); ++i) {
            dp[i][0] = true; 
        }
        
        
        for (int i = 1; i <= stones.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i][j] = dp[i - 1][j] || (j - stones[i - 1] >= 0 && dp[i - 1][j - stones[i - 1]]); 
            }
        }
        
        for (int i = sum; i >= 0; --i) {
            if (dp.back()[i]) {
                return abs((tmp - 2 * i)); 
            }
        }
        
        return -1; 
        
        
        
    }
};