// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> is;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            is.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        
        sort(is.begin(), is.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        
        
        vector<int> dp(n);
        dp[0] = profit[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            int l = 0;
            int r = i - 1;
            int last = -1;
            while(l <= r) {
                int mid = l + (r - l)/2;
                if (is[mid][1] > is[i][0]) {
                    r = mid - 1;
                } else {
                    last = mid;
                    l = mid + 1;
                }
            }
            
            if (last != -1) {
                dp[i] = max(dp[i], dp[last] + profit[i]);
            }
        }
        return dp.back();
    }
};