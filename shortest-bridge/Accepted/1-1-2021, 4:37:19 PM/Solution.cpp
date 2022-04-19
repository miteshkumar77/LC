// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        array<int, 5> dirs{0, 1, 0, -1, 0};
        
        function<void(int,int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || j < 0 || i >= m || j >= n || A[i][j] != 1) return;
            
            A[i][j] = 2;
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
        // for (auto v : A) {
        //     for (auto j : v) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        
        int shortest1 = INT_MAX - 100;
        int shortest2 = INT_MAX - 100;
        
        vector<vector<int>> dp1(m, vector<int> (n, INT_MAX - 100));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 2) {
                    dp1[i][j] = 0;
                    continue;
                }
                
                if (i != 0) {
                    dp1[i][j] = min(dp1[i - 1][j] + 1, dp1[i][j]); 
                }
                if (j != 0) {
                    dp1[i][j] = min(dp1[i][j - 1] + 1, dp1[i][j]);
                }
                
                if (A[i][j] == 1) {
                    shortest1 = min(shortest1, dp1[i][j] - 1);
                }
            }
        }
        
        // for (auto v : dp1) {
        //     for (auto j : v) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        
        dp1 = vector<vector<int>>(m, vector<int>(n, INT_MAX - 100));
        // cout << endl << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (A[i][j] == 2) {
                    dp1[i][j] = 0;
                    // cout << dp1[i][j] << ' ';
                    continue;
                }
                if (i != 0) {
                    dp1[i][j] = min(dp1[i - 1][j] + 1, dp1[i][j]);
                }
                if (j != n - 1) {
                    dp1[i][j] = min(dp1[i][j + 1] + 1, dp1[i][j]);
                }
                
                if (A[i][j] == 1) {
                    shortest2 = min(shortest2, dp1[i][j] - 1);
                }
                // cout << dp1[i][j] << ' ';
            }
            // cout << endl;
        }
        // cout << endl;
        // for (auto v : dp1) {
        //     for (auto j : v) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        
  
        return min(shortest1, shortest2);
        
    }
};