// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1)); 

        function<int(int, int)> merge = [&] (int L, int R) -> int {
            
            if (L > R) {
                return 0; 
            }
            if (dp[L][R] != -1) return dp[L][R]; 
            int ans = 0; 
            for (int i = L; i <= R; ++i) {
                ans = max(ans, merge(L, i - 1) + merge(i + 1, R) + nums[L - 1] * nums[i] * nums[R + 1]);
            }
            dp[L][R] = ans; 
            return ans; 
        };
        
        
        return merge(1, nums.size() - 2);
    }
    
    
    
    
};