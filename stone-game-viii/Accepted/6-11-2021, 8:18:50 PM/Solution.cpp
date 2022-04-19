// https://leetcode.com/problems/stone-game-viii

class Solution {
public:
    vector<int> sums;
    vector<int> dp;
    int n;
    int td(int i) {
        if (i+1 == n) return max(sums[i+1], sums[i] - sums[i+1]);
        if (i == n) return sums[i];
        if (dp[i] == -1) dp[i] = max(td(i+1), sums[i] - td(i+1));
        return dp[i];
        /*
        
        if (i + 1 == n) {
            return max(sums[i+1], sums[i] - sums[i+1]);
        } else {
            if (dp[i] == -1) {
                dp[i] = max(td(i+1), sums[i] - td(i+1));
            }
            return dp[i];
        }
        */
    } 
    int stoneGameVIII(vector<int>& stones) {
        // a1 - (b1 - (a2 - (b2 - ...)))
        n = stones.size();
        sums = vector<int>(n+1,0);
        dp = vector<int>(n+1, -1);
        for (int i = 0; i < stones.size(); ++i) {
            sums[i+1] = sums[i] + stones[i];
        }
        return td(2);
    }
};
/*
    td(1) = max(td(2), -10 - td(2)) = max(-22, -10 + 22) = 12
    td(2) = -22




*/