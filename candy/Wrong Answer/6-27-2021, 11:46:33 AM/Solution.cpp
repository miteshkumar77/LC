// https://leetcode.com/problems/candy

class Solution {
public:
    
    int sol(vector<int>& ratings, vector<int>& dp, int i) {
        if (dp[i] != -1) return dp[i];
        int ans = 1;
        int n = ratings.size();
        if (i != 0 && ratings[i-1] < ratings[i]) {
            ans = max(ans, sol(ratings, dp, i-1) + 1);
        }
        if (i + 1 != n && ratings[i+1] < ratings[i]) {
            ans = min(ans, sol(ratings, dp, i + 1) + 1);
        }
        dp[i] = ans; return dp[i];
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += sol(ratings, dp, i);
        }
        return ans;
    }
};