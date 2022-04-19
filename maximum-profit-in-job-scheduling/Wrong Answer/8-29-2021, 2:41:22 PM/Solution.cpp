// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end(), [](vector<int> const& a, vector<int> const& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n);
        dp[0] = v[0][2];
        for (int i = 1; i < n; ++i) {
            int l = 0; int r = i-1; int ans = 0; int mid;
            while(l <= r) {
                mid = l + (r - l)/2;
                if (v[mid][1] <= v[i][0]) {
                    ans = v[mid][2];
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[i] = max(dp[i-1], v[i][2] + ans);
        }
        return dp[n-1];
    }
};