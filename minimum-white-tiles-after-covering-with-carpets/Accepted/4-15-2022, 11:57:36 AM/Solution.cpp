// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets

class Solution {
public:
    int minimumWhiteTiles(string floor, int C, int L) {
        int n = floor.length();
        vector<int> prefSum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            prefSum[i] = prefSum[i-1] + (floor[i-1] == '1');
        }
        
        vector<vector<int>> dp(C+1, vector<int>(n+1, 0));
        for (int f = 0; f <= n; ++f) {
            dp[0][f] = prefSum[f];
        }
        for (int c = 1; c <= C; ++c) {
            deque<array<int,2>> minq;
            minq.push_front({0, 1});
            int lo = 1e9 + 7;
            for (int f = 1; f <= n; ++f) {
                if (f >= L) {
                    dp[c][f] = dp[c][f-1] + (floor[f-1] == '1');
                    dp[c][f] = min(dp[c][f], minq.back()[0]);
                    if (--minq.back()[1] == 0) {
                        minq.pop_back();
                    }
                } else {
                    dp[c][f] = 1e9 + 7;
                }
                array<int, 2> add{dp[c-1][f], 1};
                while(!minq.empty() && minq.front()[0] >= add[0])  {
                    add[1] += minq.front()[1];
                    minq.pop_front();
                }
                minq.push_front(add);
            }
        }
        return dp[C][n];
    }
};