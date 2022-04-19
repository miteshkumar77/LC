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
            return a[1] <= b[1];
        });
        
        // for (auto v : is) cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
        // cout << endl;
        vector<int> dp(n);
        int prev = 0;
        for (int i = 0; i < n; ++i) {
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
            // cout << last << endl;
            last = last == -1?0:dp[last];
            dp[i] = max(prev, last + is[i][2]);
            prev = dp[i];
        }
        
        // for (int i : dp) cout << i << ' ';
        return prev;
    }
};