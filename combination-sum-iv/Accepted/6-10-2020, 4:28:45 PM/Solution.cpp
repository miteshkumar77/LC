// https://leetcode.com/problems/combination-sum-iv

typedef unsigned long long int ulli; 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ulli> dp(target + 1, 0);
        dp[0] = 1; 
        for (ulli i = 0; i <= target; ++i) {
            for (ulli c : nums) {
                if (i + c <= target) {
                    dp[i + c] += dp[i]; 
                }
            }
        }
        
        return dp.back(); 
    }
};