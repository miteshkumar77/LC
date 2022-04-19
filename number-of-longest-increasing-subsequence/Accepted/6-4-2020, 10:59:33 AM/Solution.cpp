// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0; 
        int m_len = 0; 
        vector<int> dp(nums.size(), 1); 
        vector<int> dp2(nums.size(), 1); 
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1; 
                        dp2[i] = dp2[j]; 
                    } else if (dp[i] == dp[j] + 1) {
                        dp2[i] += dp2[j]; 
                    }
                }
            }
        }
        
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] == m_len) {
                ans += dp2[i];  
            } else if (dp[i] > m_len) {
                ans = dp2[i]; 
                m_len = dp[i]; 
            }
        }
        
        return ans; 
        
    }
};