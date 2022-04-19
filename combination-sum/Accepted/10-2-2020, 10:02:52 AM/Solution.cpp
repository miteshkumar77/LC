// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0].push_back(vector<int>());
        for (int cand : candidates) {
            for (int i = 0; i < dp.size(); ++i) {
                if (i + cand > target) continue;
                for (vector<int> v : dp[i]) {
                    dp[i + cand].push_back(v);
                    dp[i + cand].back().push_back(cand);
                }
            }
        }
        return dp.back();
    }
};