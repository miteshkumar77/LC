// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto v : cuboids) {
            sort(v.begin(), v.end());
        }
        
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            for (int i = 2; i >= 0; --i) {
                if (a[0] > b[0]) {
                    return true;
                } else if (a[0] < b[0]) {
                    return false;
                }
            }
            return true;
        }); 
        vector<vector<int>> p{
            {0, 1, 2},
            {1, 0, 2},
            {1, 2, 0},
            {2, 1, 0},
            {2, 0, 1},
            {0, 2, 1}
        };
        int ans = 0;
        vector<array<int, 6>> dp(n, {0,0,0,0,0,0});
        for (int i = 0; i < n; ++i) {
            for (int ri = 0; ri < 6; ++ri) {
                dp[i][ri] = cuboids[i][p[ri][0]];
                ans = max(ans, dp[i][ri]);
            }
        }
        for (int i = 1; i < n; ++i) {
            auto ci = cuboids[i];
            for (int j = 0; j < i; ++j) {
                auto cj = cuboids[j];
                for (int ri = 0; ri < 6; ++ri) {
                    for (int rj = 0; rj < 6; ++rj) {
                        bool ok = true;
                        for (int f = 0; f < 3; ++f) {
                            if (ci[p[ri][f]] > cj[p[rj][f]]) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            dp[i][ri] = max(dp[i][ri], dp[j][rj] + ci[p[ri][0]]); 
                            ans = max(ans, dp[i][ri]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};