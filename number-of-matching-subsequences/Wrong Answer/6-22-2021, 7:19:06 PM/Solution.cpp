// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(26, INT_MAX));
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
        for (string const& w : unordered_set<string>(words.begin(), words.end())) {
            si = 0;
            bool ok = true;
            for (char c : w) {
                if (dp[si][c-'a'] == INT_MAX) {
                    ok = false;
                    break;
                }
                si = dp[si][c-'a']+1;
            }
            ans += ok;
        }
        return ans;
    }
};