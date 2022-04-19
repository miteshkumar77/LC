// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    typedef array<int, 2> pii; 
    int numRollsToTarget(int d, int f, int target) {
        
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0)); 
        dp[0][0] = 1; 
        // v: value
        // r: roll number
        // a: ammount
        for (int r = 1; r <= d; ++r) {
            for (int a = 1; a <= target; ++a) {
                for (int v = 1; v <= f; ++v) {

                    if (a - v >= 0) {
                        dp[r][a] = (dp[r][a] + dp[r - 1][a - v]) % 1000000007; 
                    }
                }
            }
        }
        
        return dp.back().back(); 
        
    }
};