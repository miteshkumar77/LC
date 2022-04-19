// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.length() + 1, vector<int> (text2.length() + 1, -1)); 
        string t1 = text1; 
        string t2 = text2; 
        return helper(t1, t2, dp, text1.length(), text2.length()); 
    }
    
    int helper(string& text1, string& text2, vector<vector<int> >& dp, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j]; 
        }
        if (i == 0 || j == 0) {
            dp[i][j] = 0; 
            return 0; 
        }
        
        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = 1 + helper(text1, text2, dp, i - 1, j - 1); 
        } else {
            dp[i][j] = max(helper(text1, text2, dp, i - 1, j), helper(text1, text2, dp, i, j - 1)); 
        }
        
        return dp[i][j]; 
        
        
    
    }
};