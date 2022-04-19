// https://leetcode.com/problems/stone-game-viii

class Solution {
public:
    vector<int> sums;
    vector<int> dp;
    int n;
    int td(int i) {
        if (i == n) return sums[i];
        if (dp[i] == -1) dp[i] = max(td(i+1), sums[i] - td(i+1));
        return dp[i];
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
