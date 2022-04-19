// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs;
        jobs.reserve(n);
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](array<int, 3> const& a, array<int, 3> const& b) {
            return a[1] < b[1];
        });
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; ++i) {
            int l = 0; int r = i-1; int ans = 0;
            int mid;
            while (l <= r) {
                mid = l + (r - l)/2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    ans = dp[mid];
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[i] = max(dp[i-1], jobs[i][2] + ans);
        }
        return dp[n-1];
    }
};