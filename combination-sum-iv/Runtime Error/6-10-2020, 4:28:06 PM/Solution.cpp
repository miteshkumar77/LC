// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1; 
        for (int i = 0; i <= target; ++i) {
            for (int c : nums) {
                if (i + c <= target) {
                    dp[i + c] += dp[i]; 
                }
            }
        }
        
        return dp.back(); 
    }
};