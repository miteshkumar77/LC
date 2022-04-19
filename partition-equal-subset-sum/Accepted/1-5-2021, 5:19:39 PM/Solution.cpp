// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0); 
        if (total % 2 == 1) return false;
        total /= 2;
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        
        for (int n : nums) {
            for (int t = total; t >= 1; --t) {
                dp[t] = dp[t] or (t - n >= 0 && dp[t-n]);
            }
            if (dp.back()) {
                return true;
            }
        }
        return false;
        
    }
};