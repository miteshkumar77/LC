// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        array<int, 5> dirs{0, 1, 0, -1, 0};
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> bfsq;
        
        
        function<void(int,int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || j < 0 || i >= m || j >= n || A[i][j] != 1) return;
            
            A[i][j] = 2;
            dist[i][j] = 0;
            bfsq.push(make_pair(i,j));
            
            for (int x = 0; x < 4; ++x) {
                dfs(i + dirs[x], j + dirs[x + 1]); 
            }
        };
        
        for (int i = 0; i < m; ++i) {
            bool brk = false;
            for (int j = 0; j < n; ++j) {
                if (A[i][j]) {
                    brk = true;
                    dfs(i,j);
                    break;
                }
            }
            if (brk) break;
        }
        int ans = INT_MAX;
        while(!bfsq.empty()) {
            auto [i, j] = bfsq.front(); bfsq.pop();
            for (int x = 0; x < 4; ++x) {
                int ni = i + dirs[x]; int nj = j + dirs[x + 1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    if (A[ni][nj] == 1) {
                        ans = min(ans, dist[ni][nj] - 1);
                        continue;
                    }
                    bfsq.push(make_pair(ni, nj));
                }
            }
        }
        
        return ans;

        
    }
};