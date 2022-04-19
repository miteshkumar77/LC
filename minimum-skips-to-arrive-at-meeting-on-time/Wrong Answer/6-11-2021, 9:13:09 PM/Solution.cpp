// https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time

class Solution {
public:
    bool check(vector<int>& dist, int speed, int limit, int skips) {
        int n = dist.size();
        vector<vector<long double>> dp(n+1, vector<long double>(skips + 1, 0.0));
        long double diff = INT_MAX;
        for (int i = 1; i <= n; ++i) dp[i][0] = ceil(dp[i-1][0]) + (long double)dist[i-1]/(long double)speed;
        if (dp[n][0] <= limit) return true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= skips; ++j) {
                
                dp[i][j] = min(dp[i-1][j-1] + (long double)dist[i-1]/(long double)speed, ceil(dp[i-1][j]) + (long double)dist[i-1]/(double)speed);
                diff = min(diff, limit-dp[i][j]);
                if (i == n && dp[i][j] <= limit) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        int l = 0;
        int r = n;
        int ans = -1;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(dist, speed, hoursBefore, mid)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};