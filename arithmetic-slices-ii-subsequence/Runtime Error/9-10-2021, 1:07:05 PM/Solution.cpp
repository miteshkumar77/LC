// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<int,array<int,2>>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                if (!dp[i].count(diff)) {
                    dp[i][diff] = {0,0};
                }
                ++dp[i][diff][0];
                if (dp[j].count(diff)) {
                    dp[i][diff][1] += dp[j][diff][0] + dp[j][diff][1];
                }
            }
            for (auto p : dp[i]) {
                ans += p.second[1];
            }
        }
        return ans;
    }
};