// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end()); 
        
        
        // int Lptr = 0; int Rptr = cuts.size() - 1; 
        // int Llen = 0; int Rlen = n; 
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); 
        function<int(int,int,int,int)> sol = [&] (int Lptr, int Rptr, int Llen, int Rlen) -> int {
            if (dp[Llen][Rlen] != -1) {
                return dp[Llen][Rlen]; 
            }
            if (Lptr > Rptr) {
                return 0; 
            }
            int ans = INT_MAX; 
            for (int i = Lptr; i <= Rptr; ++i) {
                int sub = sol(Lptr, i - 1, Llen, cuts[i]) + sol(i + 1, Rptr, cuts[i], Rlen) + Rlen - Llen;  
                ans = min(ans, sub); 
            }
            dp[Llen][Rlen] = ans; 
            return ans; 
        }; 
        return sol(0, cuts.size() - 1, 0, n); 
    }
};