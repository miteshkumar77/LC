// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        
        int C = cuts.size();
        vector<vector<int>> dp(C, vector<int>(C, -1));
        /*
            dp[i][j] = min cost to make cuts i through j 
        */
        
        function<int(int,int,int,int)> sol = [&](int l, int r, int left, int right) -> int {
            if (r < l) return 0;
            
            if (dp[l][r] != -1) return dp[l][r];
            int ans = INT_MAX;
            for (int c = l; c <= r; ++c) {
                ans = min(ans, right - left + sol(l, c - 1, left, cuts[c]) + sol(c + 1, r, cuts[c], right));
            }
            dp[l][r] = ans;
            return ans;
        };
        
        return sol(0, C - 1, 0, n); 
    }
};