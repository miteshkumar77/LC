// https://leetcode.com/problems/best-meeting-point

class Solution {
public:
    int dist(array<int, 2> a, array<int, 2> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> vdp(n + 1, 0);
        vector<int> hdp(m + 1, 0);
        for (int i = 0; i < n; ++i) {
            vdp[i+1] = vdp[i] + accumulate(grid[i].begin(), grid[i].end(), 0);
        }
        for (int i = 0; i < m; ++i) {
            hdp[i+1] = hdp[i];
            for (int j = 0; j < n; ++j) hdp[i+1] += grid[j][i];
        }
        
        int lans = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               if (grid[i][j]) 
                    lans += dist({0, 0}, {i, j});
            }
        }
        //cout << lans << endl;
        for (int i = 0; i < n; ++i) {
            if (i == 0) grid[i][0] = lans;
            else grid[i][0] = grid[i-1][0] + vdp[i] - (vdp.back() - vdp[i]);
            ans = min(ans, grid[i][0]);
            for (int j = 1; j < m; ++j) {
                grid[i][j] = grid[i][j-1] + hdp[j] - (hdp.back() - hdp[j]);
                ans = min(ans, grid[i][j]);
            }
        }
        //for (const auto& v : grid){
        //    for (int i : v) cout << i << ' ';
        //    cout << endl;
        //}
        return ans;
    }
};