// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ansidx = 0;
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[0] = vector<int>();
        
        for (int i = 1; i <= n; ++i) {
            int maxidx = 0;
            for (int j = 1; j < i; ++j) {
                if (nums[i - 1] % dp[j].back() == 0 && dp[maxidx].size() < dp[j].size()) {
                    maxidx = j;
                }
            }
            
            dp[i] = vector<int>(dp[maxidx].begin(), dp[maxidx].end());
            dp[i].push_back(nums[i - 1]);
            if (dp[i].size() > dp[ansidx].size()) {
                ansidx = i;
            }
        }
        
        return dp[ansidx];
        
        
        
    }
};