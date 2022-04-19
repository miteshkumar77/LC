// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1); 
        dp[0] = 0; 
        for (int i = 0; i <= num; ++i) {
            dp[i] = dp[i&(i - 1)] + 1; 
        }
        return dp; 
    }
};