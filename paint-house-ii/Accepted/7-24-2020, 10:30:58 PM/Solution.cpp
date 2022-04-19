// https://leetcode.com/problems/paint-house-ii

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // if (costs.size() > 1 && costs[0].size() <= 1) {
        //     return -1; 
        // }
        if (costs.size() == 0 || costs[0].size() == 0) {
            return 0; 
        }
        int n = costs.size(); 
        int k = costs[0].size(); 
        vector<vector<int> > dp(n + 1, vector<int>(k, 0));
        
        vector<int> prefmin(k + 2, 0);
        vector<int> suffmin(k + 2, 0); 
        
        for (int i = 1; i <= n; ++i) {
            
            for (int x = 1, y = k; x <= k; ++x, --y) {
                prefmin[x] = min(prefmin[x - 1], dp[i - 1][x - 1]); 
                suffmin[y] = min(suffmin[y + 1], dp[i - 1][y - 1]); 
            }
            
            for (int j = 1; j <= k; ++j) {
                dp[i][j - 1] = min((unsigned long long int)min(prefmin[j - 1], suffmin[j + 1]) + (unsigned long long int)costs[i - 1][j - 1], (unsigned long long int)INT_MAX); 
            }
            prefmin[0] = INT_MAX; 
            suffmin[k + 1] = INT_MAX; 
        }
        
        int ans = INT_MAX; 
        for (int i = 0; i < k; ++i) {
            ans = min(ans, dp.back()[i]); 
        }
        return ans; 
    }
};