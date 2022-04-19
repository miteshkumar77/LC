// https://leetcode.com/problems/palindrome-partitioning-iii

class Solution {
public:
    typedef unsigned long long int ulli;
    int palindromePartition(string s, int k) {
        
        int n = s.length();
        if (k >= n) {
            return 0;
        }
        s = '#' + s;
        vector<vector<int>> nc(n + 1, vector<int>(n + 1, -1));
        function<int(int,int)> num_changes = [&](int i, int j) -> int {
            if (i >= j) {
                return 0;
            }
            if (nc[i][j] != -1) return nc[i][j];
            nc[i][j] = (s[i] != s[j]) + num_changes(i + 1, j - 1);
            return nc[i][j];
        };
        
        
        vector<vector<ulli>> dp(k + 1, vector<ulli>(n + 1, INT_MAX));
        
        // dp[c][i] = minimum cost to cut s[0...i] c times.
        dp[0][0] = 0;
        for (int c = 1; c <= k; ++c) {
            for (int i = c; i + k - c <= n; ++i) {
                for (int x = c - 1; x < i; ++x) {
                    dp[c][i] = min(dp[c][i], dp[c - 1][x] + num_changes(x + 1, i));
                }
            }
        }
        return dp.back().back();
    }
};