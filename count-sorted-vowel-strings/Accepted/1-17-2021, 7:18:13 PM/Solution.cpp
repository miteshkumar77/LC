// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);        
        
        for (int c = 1; c < n; ++c) {
            for (int v = 0; v < 5; ++v) {
                if  (v != 0) dp[v] += dp[v - 1];
            }
        }
        int ans = 0;
        for (int v = 0; v < 5; ++v) ans += dp[v];
        return ans;
    }
};