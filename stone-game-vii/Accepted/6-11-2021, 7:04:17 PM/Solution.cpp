// https://leetcode.com/problems/stone-game-vii

class Solution {
public:
    
    // a1 - (b1 - (a2 - (b2 - ...)))
    vector<int> sums;
    int td(int l, int r, vector<vector<int>>& dp, vector<int>& stones) {
        if (l > r) return false;
        
        if (dp[l][r] == -1) {
            int sm = sums[r+1]-sums[l];
            int rl = td(l+1, r, dp, stones);
            int rr = td(l, r-1, dp, stones);
            dp[l][r] = max(sm - stones[l] - rl, sm - stones[r] - rr);
        }
        return dp[l][r];
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        sums = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + stones[i-1];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return td(0, n-1, dp, stones);
    }
};