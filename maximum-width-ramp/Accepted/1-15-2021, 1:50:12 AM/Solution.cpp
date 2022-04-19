// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        vector<pair<int,int>> p; p.reserve(n);
        for (int i = 0; i < n; ++i) {
            p.push_back({A[i], i});
        }
        sort(p.begin(), p.end());
        
       
        int ret = 0;
        vector<int> dp(n);
        dp[0] = p[0].second;
        for (int i = 1; i < n; ++i) {
            ret = max(ret, max(0, p[i].second - dp[i - 1]));
            dp[i] = min(dp[i - 1], p[i].second);
        }
        return ret;
    }
};