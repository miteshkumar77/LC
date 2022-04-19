// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones

class Solution {
public:
    
    
    
    int findIntegers(int n) {
        /*
            dp[i][0]: ending with 0 and bounded
            dp[i][1]: ending with 1 and bounded
            dp[i][2]: ending with 0 and unbounded
            dp[i][3]: ending with 1 and unbounded
        */    
        string bin;
        while(n) {
            bin.push_back(((n&1) + '0'));
            n >>= 1;
        }
        reverse(bin.begin(), bin.end());
        n = bin.length();
        vector<array<int,4>> dp(n+1, {1, 0, 0, 0});
        for (int i = 1; i <= n; ++i) {
            int c = bin[i-1] - '0';
            if (c == 0) {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = 0;
                
                dp[i][2] = dp[i-1][2] + dp[i-1][3];
                dp[i][3] = dp[i-1][2];
            } else {
                dp[i][0] = 0;
                dp[i][1] = dp[i-1][0];
                
                dp[i][2] = dp[i-1][2] + dp[i-1][3] + dp[i-1][0] + dp[i-1][1];
                dp[i][3] = dp[i-1][2];
            }
        }
        return dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];
    }
};