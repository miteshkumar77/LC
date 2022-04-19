// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<int> r(n, 0);
        vector<int> c(m, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                r[i] += grid[i][j];
                c[j] += grid[i][j];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += ((r[i] > 1 || c[j] > 1) && grid[i][j]);
            }
        }
        return ans;
    }
};