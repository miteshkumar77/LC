// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
public:
    int solve(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>((n+1)/3 + 1, 0));
        /*
            dp[i][j]: max score if we will have picked j pizzas 
                from pizzas 0 ... i.
        */
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, (n+1)/3); ++j) {
                if (i == 1) {
                    dp[i][j] = max(dp[i-1][j], s[i-1]);
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-2][j-1] + s[i-1]);
                }
            }
            ans = max(ans, dp[i][(n+1)/3]);
        }
        return ans;
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> a(slices.begin(), prev(slices.end()));
        vector<int> b(slices.begin() + 1, slices.end());
        return max(solve(a), solve(b));
    }
};

































