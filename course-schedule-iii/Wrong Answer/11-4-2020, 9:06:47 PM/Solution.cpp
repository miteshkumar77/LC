// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] - a[0] < b[1] - b[0];
        });
        int n = courses.size();
        vector<vector<int>> dp(n + 1, vector<int>(10001, 0));
        
        // dp[c][d] = maximum number of courses if we complete course c on day d
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            for (int d = 1; d <= courses[c - 1][1]; ++d) {
                if (d - courses[c - 1][0] >= 0) {
                    dp[c][d] = max(dp[c - 1][d - courses[c - 1][0]] + 1, dp[c - 1][d]);
                } else {
                    dp[c][d] = dp[c - 1][d];
                }
                ans = max(ans, dp[c][d]);
            }
        }
        return ans;
        
        
    }
};