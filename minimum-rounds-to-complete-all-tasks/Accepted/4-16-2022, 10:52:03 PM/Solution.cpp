// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for (int i = 2; i <= n; ++i) {
            if (tasks[i-1] == tasks[i-2] && dp[i-2] != -1) {
                dp[i] = dp[i-2] + 1;
            }
            if (i >= 3 && tasks[i-1] == tasks[i-3] && dp[i-3] != -1) {
                if (dp[i] == -1) {
                    dp[i] = dp[i-3]+1;
                } else {
                    dp[i] = min(dp[i], dp[i-3] + 1);
                }
            }
        }
        return dp[n];
    }
};