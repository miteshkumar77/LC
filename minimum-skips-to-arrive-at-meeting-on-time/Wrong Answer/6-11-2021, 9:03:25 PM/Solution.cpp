// https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time

class Solution {
public:
    bool check(vector<int>& dist, int speed, int limit, int skips) {
        int n = dist.size();
        vector<vector<double>> dp(n+1, vector<double>(skips + 1, 0.0));
        for (int i = 1; i <= n; ++i) dp[i][0] = ceil(dp[i-1][0]) + (double)dist[i-1]/(double)speed;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= skips; ++j) {
                dp[i][j] = min(dp[i-1][j-1] + (double)dist[i-1]/(double)speed, ceil(dp[i-1][j] + (double)dist[i-1]/(double)speed));
                if (i == n && dp[i][j] <= limit) return true;
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