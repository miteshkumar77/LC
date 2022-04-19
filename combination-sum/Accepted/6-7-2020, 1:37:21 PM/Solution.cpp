// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int> > > dp(target + 1, vector<vector<int> >()); 
        dp[0].push_back(vector<int>()); 
        
        for (int c : candidates) {
            for (int i = 0; i <= target; ++i) {
                for (vector<int> c_set : dp[i]) {
                    if (i + c < dp.size()) {
                        dp[i + c].push_back(c_set); 
                        dp[i + c].back().push_back(c); 
                    }
                }
            }
        }
        return dp.back(); 
    }
    
    
    
};