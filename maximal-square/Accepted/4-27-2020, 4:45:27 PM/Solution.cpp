// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0; 
        }
        vector<vector<int> > dp = vector<vector<int> >(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)); 
        
         
        int max_area = 0; 
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0; 
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]); 
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
                    ++dp[i][j];
                    if (dp[i][j] * dp[i][j] > max_area) {
                        max_area = dp[i][j] * dp[i][j];
                    }
                }
                    
                
            }
        }
        
        return max_area; 
        
    }
};