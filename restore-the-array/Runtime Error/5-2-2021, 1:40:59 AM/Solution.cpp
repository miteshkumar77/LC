// https://leetcode.com/problems/restore-the-array

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int mul;
        int num;
        int j;
        int M = 1e9 + 7;
        //for (int i : dp) cout << i << ' ';
        //cout << endl;
        for (int i = 1; i <= n; ++i) {
            mul = 1;
            num = 0;
            j = i;
            while(j >= 1 && num <= k) {
                num += mul * (s[--j] - '0');
               if (mul < INT_MAX/10) { 
                    mul *= 10;
               }
                
                if (s[j] != '0' && num >= 1 && num <= k) {
                    dp[i] += dp[j];
                    dp[i] %= M;
                }
            }
            if (dp[i] == 0 && s[i - 1] == '0') {
                return 0;
            }
            // for (int i : dp) cout << i << ' ';
            // cout << endl;
        }
        return dp.back();
    }
};