// https://leetcode.com/problems/trapping-rain-water-ii

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        int imin = -1e9;
        vector<vector<array<int, 2>>> dpv(n + 2, vector<array<int, 2>>(m + 2, {imin, imin}));
        vector<vector<array<int, 2>>> dph(n + 2, vector<array<int, 2>>(m + 2, {imin, imin}));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dpv[i + 1][j + 1][0] = max(dpv[i][j + 1][0], heightMap[i][j]);
                dph[i + 1][j + 1][0] = max(dph[i + 1][j][0], heightMap[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                dpv[i + 1][j + 1][1] = max(dpv[i + 2][j + 1][1], heightMap[i][j]);
                dph[i + 1][j + 1][1] = max(dph[i + 1][j + 2][1], heightMap[i][j]);
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int v = min(dpv[i - 1][j][0], dpv[i + 1][j][1]);
                int h = min(dph[i][j - 1][0], dph[i][j + 1][1]);
                ans += max(0, min(v, h) - heightMap[i - 1][j - 1]);
            }
        }
        return ans;
    }
};