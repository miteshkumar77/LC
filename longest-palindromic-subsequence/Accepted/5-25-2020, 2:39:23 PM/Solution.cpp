// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.length(), vector<int>(s.length(), -1));
        string i = s; 
        return helper(i, 0, s.length() - 1, dp); 
    }
    
    
    int helper(string& s, int L, int R, vector<vector<int> >& dp) {
        if (dp[L][R] != -1) {
            return dp[L][R]; 
        }
        if (L > R) {
            dp[L][R] = 0; 
            return dp[L][R]; 
        }
        if (L == R) {
            dp[L][R] = 1; 
            return dp[L][R]; 
        }
        
        int left_subproblem = helper(s, L , R - 1, dp); 
        int right_subproblem = helper(s, L + 1, R, dp); 
        int center_subproblem = helper(s, L + 1, R - 1, dp); 
        if (s[L] == s[R]) {
            center_subproblem += 2; 
        }
        
        // cout << "("<< L << ", " << R << "): " << left_subproblem << ' ' << right_subproblem << ' ' << center_subproblem << endl; 
        
        dp[L][R] = max(left_subproblem, max(right_subproblem, center_subproblem)); 
        return dp[L][R]; 
    }
};