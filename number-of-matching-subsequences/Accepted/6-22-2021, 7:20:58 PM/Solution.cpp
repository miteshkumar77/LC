// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(26, n));
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (s[i]-'a' == j) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        int ans = 0;   
        int si;
        unordered_map<string,int> ct;
        for (string const& w : words) ++ct[w];
        for (auto const& [w,c] : ct) {
            si = 0;
            bool ok = true;
            for (char c : w) {
                if (dp[si][c-'a'] == n) {
                    ok = false;
                    break;
                }
                si = dp[si][c-'a']+1;
            }
            ans += ok * c;
        }
        return ans;
    }
};