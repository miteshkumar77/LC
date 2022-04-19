// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    
    static inline bool checkOut(int m, int n, int i, int j) {
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
        int M = 1e9 + 7;
        array<int, 5> dirs{0, 1, 0, -1, 0};
        
        
        function<int(int,int,int)> sol = [&](int ii, int jj, int NN) -> int{
            if (checkOut(m, n, ii, jj)) {
                return 1;
            }
            if (NN == 0) {
                return 0;
            }
            
            if (dp[ii][jj][NN] != -1) {
                return dp[ii][jj][NN];
            }
            int ans = 0;
            for (int x = 0; x < 4; ++x) {
                ans = (ans + sol(ii + dirs[x], jj + dirs[x + 1], NN - 1)) % M; 
            }
            dp[ii][jj][NN] = ans;
            return ans;
        };
        
        return sol(i, j, N);
    }
};