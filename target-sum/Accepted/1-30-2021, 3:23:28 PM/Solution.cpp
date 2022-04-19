// https://leetcode.com/problems/target-sum

class Solution {
public:
    typedef signed long long int slli;
    slli zero = 0; 
    slli& get(slli i, slli j, vector<vector<slli>>& v) {
        slli offset = ((slli)v[0].size() - 1)/2;
        if (j + offset < 0 || j + offset >= v[0].size()) {
            return zero;
        }
        return v[i][j + offset]; 
    }
    
    int findTargetSumWays(vector<int>& nums, slli S) {
        slli n = nums.size(); 
        slli mag = accumulate(nums.begin(), nums.end(), 0); 
        slli m = mag * 2; 
        vector<vector<slli>> dp(n + 1, vector<slli>(m + 1, 0)); 
        get(0, 0, dp) = 1; 
        slli num;
        for (slli i = 1; i <= n; ++i) {
            num = nums[i - 1];
            for (slli j = mag - mag - mag; j <= mag; ++j) {
                get(i, j, dp) = get(i - 1, j - num, dp) + get(i - 1, j + num, dp); 
            }
        }
        
        return get(n, S, dp); 
        
        
    }
};