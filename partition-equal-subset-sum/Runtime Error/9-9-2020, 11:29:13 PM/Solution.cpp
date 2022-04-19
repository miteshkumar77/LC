// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0; 
        for (int i : nums) {
            tsum += i; 
        }
        if (tsum % 2 != 0) {
            return false; 
        }
        
        tsum /= 2; 
        
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(tsum + 1, false));
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = true; 
        }
        
        for (int c = 1; c <= dp.size(); ++c) {
            for (int amt = 1; amt <= tsum; ++amt) {
                dp[c][amt] = dp[c - 1][amt] || (amt >= nums[c - 1] && dp[c - 1][amt - nums[c - 1]]);
                if (amt == tsum && dp[c][amt]) {
                    return true; 
                }
            }
        }
        
        return false; 
        
    }
};