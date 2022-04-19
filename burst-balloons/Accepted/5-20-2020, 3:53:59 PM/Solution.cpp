// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); 
        nums.push_back(1);
        vector<vector<int> > dp(nums.size() + 2, vector<int>(nums.size() + 2, -1)); 

        return helper(nums, 1, nums.size() - 2, dp); 
    }
    
    int helper(vector<int>& nums, int L, int R, vector<vector<int> >& dp) {

        if (dp[L][R] != -1) {
            return dp[L][R]; 
        }

        if (L == R) {
            dp[L][R] = nums[L - 1] * nums[L] * nums[R + 1]; 
            return dp[L][R];
        }

        int ans = 0; 
        for (int i = L; i <= R; ++i) {
            int left_problem = 0;
            int right_problem = 0; 

            if (i != L) {
                left_problem = helper(nums, L, i - 1, dp); 
            } 

            if (i != R) {
                right_problem = helper(nums, i + 1, R, dp); 
            }
    
            int tmp_ans = right_problem + left_problem + nums[i] * nums[L - 1] * nums[R + 1]; 
            if (tmp_ans > ans) {
                ans = tmp_ans; 
            }
        }
        
        dp[L][R] = ans; 
        return dp[L][R]; 
    }
    
};