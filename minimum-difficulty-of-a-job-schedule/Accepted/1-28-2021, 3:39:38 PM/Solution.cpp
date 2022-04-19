// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:
    
    int sol(int day, int end, vector<vector<int>>& dp, vector<int>& jobs) {
        if (day == 0) {
            dp[day][end] = *max_element(jobs.begin(), jobs.begin() + end + 1); 
            return dp[day][end];
        }
        if (dp[day][end] != -1) return dp[day][end];
        int mval = 0;
        int ans = INT_MAX;
        for (int i = end; i >= day; --i) {
            mval = max(mval, jobs[i]);
            ans = min(ans, mval + sol(day - 1, i - 1, dp, jobs));
        }
        dp[day][end] = ans;
        return ans;
    }
    
    int minDifficulty(vector<int>& jobs, int d) { 
        int n = jobs.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n, -1));
        int a = sol(d - 1, n - 1, dp, jobs); 
        return a;
    }
};