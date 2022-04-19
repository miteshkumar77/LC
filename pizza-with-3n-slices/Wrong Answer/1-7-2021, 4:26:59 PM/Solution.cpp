// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int ans = 0;
        for (int i = 0; i < slices.size(); ++i) {
            slices.insert(slices.begin(), slices.back());
            slices.pop_back();
            
            ans = max(ans, solveOne(slices));
        }
        return ans;
    }
    
    int solveOne(vector<int>& slices) {
        int n = slices.size(); 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        function<int(int,int)> dfs = [&](int l, int r) -> int {
            // cout << l << ' ' << r << endl;
            if (l > r) return 0;
            if ((r - l + 1) % 3 != 0) return INT_MIN;
            if (dp[l][r] != -1) return dp[l][r];
            int ans = INT_MIN;
            for (int i = l + 1; i < r; ++i) {
                int lres = dfs(l + 1, i - 1);
                int rres = dfs(i + 1, r - 1);
                if (lres >= 0 && rres >= 0) {
                    ans = max(ans, lres + rres + slices[i]);
                }
            }
            dp[l][r] = ans;
            return dp[l][r];
        };
        
        return dfs(0, n - 1);
    }
};