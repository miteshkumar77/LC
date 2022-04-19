// https://leetcode.com/problems/maximum-points-in-an-archery-competition

class Solution {
public:
    /*
        x used in prev
        y used in total
        
    */
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<vector<int>> dp(n, vector<int>(numArrows+1, 0));
        vector<vector<bool>> exe(n, vector<bool>(numArrows+1, 0));
        for (int i = 1; i < n; ++i) {
            for (int a = 1; a <= numArrows; ++a) {
                dp[i][a] = dp[i-1][a];
                if (a > aliceArrows[i]) {
                    // dp[i][a] = max(dp[i][a], dp[i-1][a-aliceArrows[i]-1] + i);
                    int tmp = dp[i-1][a-aliceArrows[i]-1] + i;
                    if (dp[i][a] < tmp) {
                        exe[i][a] = true;
                        dp[i][a] = tmp;
                    }
                }
            }
        }
        
        int total = numArrows;
        vector<int> ans(n);
        for (int i = n-1; i >= 0; --i) {
            if (exe[i][total]) {
                ans[i] = aliceArrows[i]+1;
                total -= (aliceArrows[i]+1);
            }
        }
        ans[0] += total;
        return ans;
        
    }
};