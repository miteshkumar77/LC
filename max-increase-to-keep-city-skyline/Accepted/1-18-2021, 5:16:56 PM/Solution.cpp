// https://leetcode.com/problems/max-increase-to-keep-city-skyline

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> rows(m, INT_MIN);
        vector<int> cols(m, INT_MIN); 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                rows[i] = max(grid[i][j], rows[i]);
                cols[j] = max(grid[i][j], cols[j]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        return ans;
    }
};