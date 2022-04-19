// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    
    /*
        
        dp[i][k] = minimum cost from splitting nums[0:i+1] into k subarrays

    */
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(); 
        vector<int> dp(n, 0); 
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
        int total = dp.back(); 
        int ktotal;
        int itotal;
        for (int k = 2; k <= m; ++k) {
            ktotal = total;
            for (int i = n - 1; i >= 0; --i) {
                dp[i] = INT_MAX;
                itotal = 0; 
                for (int j = i - 1; j + 2 >= k; --j) {
                    itotal += nums[j + 1]; 
                    dp[i] = min(dp[i], max(dp[j], itotal)); 
                }
            }
        }
        return dp.back(); 
    }
};