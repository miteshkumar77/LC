// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path

class Solution {
public:
    
    int intlog(int base, int x) {
        int ans{0};
        while(x % base == 0) {
            x /= base;
            ++ans;
        }
        return ans;
    } 
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();    
        vector<vector<array<int,2>>> up(n+2, vector<array<int,2>>(m+2, {0, 0}));
        vector<vector<array<int,2>>> dn(n+2, vector<array<int,2>>(m+2, {0, 0}));
        vector<vector<array<int,2>>> le(n+2, vector<array<int,2>>(m+2, {0, 0}));
        vector<vector<array<int,2>>> ri(n+2, vector<array<int,2>>(m+2, {0, 0}));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int nf = (grid[i-1][j-1] % 5 == 0) ? intlog(5, grid[i-1][j-1]) : 0;
                int nt = (grid[i-1][j-1] % 2 == 0) ? intlog(2, grid[i-1][j-1]) : 0;
                up[i][j] = {up[i-1][j][0] + nf, up[i-1][j][1] + nt};
                le[i][j] = {le[i][j-1][0] + nf, le[i][j-1][1] + nt};
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = m; j >= 1; --j) {
                int nf = (grid[i-1][j-1] % 5 == 0) ? intlog(5, grid[i-1][j-1]) : 0;
                int nt = (grid[i-1][j-1] % 2 == 0) ? intlog(2, grid[i-1][j-1]) : 0;
                dn[i][j] = {dn[i+1][j][0] + nf, dn[i+1][j][1] + nt};
                ri[i][j] = {ri[i][j+1][0] + nf, ri[i][j+1][1] + nt};
            }
        }
        int ans{0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int nf = (grid[i-1][j-1] % 5 == 0) ? intlog(5, grid[i-1][j-1]) : 0;
                int nt = (grid[i-1][j-1] % 2 == 0) ? intlog(2, grid[i-1][j-1]) : 0;
                int amt1 = min(up[i][j][0] + le[i][j][0] - nf, up[i][j][1] + le[i][j][1] - nt);
                int amt2 = min(up[i][j][0] + ri[i][j][0] - nf, up[i][j][1] + ri[i][j][1] - nt);
                int amt3 = min(dn[i][j][0] + ri[i][j][0] - nf, up[i][j][1] + ri[i][j][1] - nt);
                int amt4 = min(dn[i][j][0] + le[i][j][0] - nf, dn[i][j][1] + le[i][j][1] - nt);
                int amt = max(amt1, max(amt2, max(amt3, amt4)));
                ans = max(ans, amt);
            }
        }
        return ans;
    }
};