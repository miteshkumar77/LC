// https://leetcode.com/problems/letter-tile-possibilities

class Solution {
public:
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size(); 
        vector<int> fact(n + 3, 1);
        for (int i = 1; i <= n + 2; ++i) fact[i] = i * fact[i - 1];

        array<int, 26> ct;
        fill(ct.begin(), ct.end(), 0); 
        for (char c : tiles) ++ct[c - 'A']; 
        
        // dp[i][j] = number of possible sequences including character i of length j. 
        
        vector<vector<int>> dp(27, vector<int>(n + 1, 0)); 
        dp[0][0] = 1;
        
        for (int tile = 1; tile <= 26; ++tile) {
            for (int length = 0; length <= n; ++length) {
                for (int include = 0; include <= ct[tile - 1]; ++include) {
                    if (length - include >= 0) {
                        dp[tile][length] += dp[tile - 1][length - include] * (fact[length]/(fact[length-include] * fact[include])); 
                    }
                }
            }
        }
        
        return accumulate(dp.back().begin() + 1, dp.back().end(), 0); 
    }
};