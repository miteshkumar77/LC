// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    typedef vector<vector<int>> ans_t;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int> ct;
        for (int i : candidates) ++ct[i];
        vector<array<int,2>> can; can.reserve(ct.size());
        for (auto const& p : ct) can.push_back({p.first, p.second});
        int n = can.size();
        vector<ans_t> dp(target + 1);
        dp[0].push_back(vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = target; j > 0; --j) {
                for (int k = 1; k <= can[i][1]; ++k) {
                    if (j - can[i][0] * k >= 0) {
                        for (auto v : dp[j-can[i][0]*k]) {
                            dp[j].push_back(v);
                            for (int x = 0; x < k; ++x) {
                                dp[j].back().push_back(can[i][0]);
                            }
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};