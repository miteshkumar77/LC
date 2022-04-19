// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    typedef array<int, 2> pii; 
    int numRollsToTarget(int d, int f, int target) {
        // int mod = 100000007; 
        int mod = 1000000007; 
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0)); 
        dp[0][0] = 1; 
        // r: roll number
        // a: ammount
        for (int r = 1; r <= d; ++r) {
            unsigned long long int pr = 0; 
            for (int a = 1; a <= target; ++a) {
                pr = (pr + dp[r - 1][a - 1]) % mod;
                if (a >= f + 1) {
                    pr = (pr + mod - dp[r - 1][a - f - 1]) % mod; 
                }
                dp[r][a] = (dp[r][a] + pr) % mod; 
            }
        }
        
        return dp.back().back(); 
        
    }
};