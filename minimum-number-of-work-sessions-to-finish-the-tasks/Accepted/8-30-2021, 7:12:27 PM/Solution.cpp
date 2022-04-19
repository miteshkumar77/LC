// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    int solve(int S, int k, vector<int>& tasks, int sessionTime, vector<vector<int>>& dp) {
        if (S == 0) return 0;
        if (k == 0) return -2;
        if (dp[S][k] != -1) return dp[S][k];
        int pow = 1;
        int ans = -2;
        for (int i = 0; i < tasks.size(); ++i, pow <<= 1) {
            if (S & pow) {
                S &= ~pow;
                int a1 = solve(S, k-1, tasks, sessionTime, dp);
                int a2 = solve(S, k, tasks, sessionTime, dp);
                S |= pow;
                if (a1 != -2) {
                    if (ans == -2) {
                        ans = tasks[i];
                    } else {
                        ans = min(ans, tasks[i]);
                    }
                } else if (a2 != -2 && a2 + tasks[i] <= sessionTime) {
                    
                    if (ans == -2) {
                        ans = tasks[i] + a2;
                    } else {
                        ans = min(ans, tasks[i] + a2);
                    }
                }
            }
        }
        dp[S][k] = ans;
        return ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<vector<int>> dp(2 << (n+1), vector<int>(n+1, -1));
        int S = 0;
        int pow = 1;
        for (int i = 0; i < n; ++i, pow <<= 1) {
            S |= pow;
        }
        for (int i = 1; i <= n; ++i) {
            if (solve(S, i, tasks, sessionTime, dp) != -2) {
                return i;
            }
        }
        return -1;
    }
};