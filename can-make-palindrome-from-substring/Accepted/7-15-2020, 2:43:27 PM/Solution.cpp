// https://leetcode.com/problems/can-make-palindrome-from-substring

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        vector<bool> ans; 
        vector<array<int, 26> > dp(s.length() + 1, array<int, 26>{0});
        
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = dp[i - 1][j]; 
            }
            ++dp[i][s[i - 1] - 'a'];
            
        }
        
        for (vector<int> q : queries) {
            ans.push_back(evalQuery(q, dp)); 
        }
        return ans; 
    }
    
    
    bool evalQuery(vector<int>& q, vector<array<int, 26>>& dp) {
        int left = q[0]; 
        int right = q[1]; 
        int k = q[2]; 
        
        
        
        array<int, 26> diff;
        for (int i = 0; i < 26; ++i) {
            diff[i] = dp[right + 1][i] - dp[left][i]; 
        }
            
        int x = 0; 
        for (int i = 0; i < 26; ++i) {
            x += (diff[i] % 2);   
        }
        return ((int)(x/2)) <= k; 
        
    }
};