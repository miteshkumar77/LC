// https://leetcode.com/problems/minimum-absolute-difference-queries

#define MAXN 29
#define MX 100000000
#define MI -MX
class Solution {
public:
    

    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); int q = queries.size();
        vector<vector<int>> dp(n + 1, vector<int>(101, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                dp[i][j] = dp[i-1][j] + (nums[i-1] == j);
            }
        }
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            ans[i] = MX;
            int prev = MI;
            int curr = 0;
            for (int j = 1; j <= 100; ++j) {
                curr = dp[queries[i][1]+1][j] - dp[queries[i][0]][j];
                if (curr) {
                    ans[i] = min(ans[i], j-prev);
                    prev = j;
                    if (ans[i] == 1) break;
                }
            }
            ans[i] = ans[i] == MX ? -1 : ans[i];
        }
        return ans;
        
    }
};