// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.length() == 0) {
            return 0; 
        }
        vector<vector<pair<int, int> > > dp = vector<vector<pair<int, int> > >(matrix.size() + 1, vector<pair<int, int> >(matrix[0].size() + 1, pair<int, int>(0, 0))); 
        
        pair<int, int> zp = pair<int, int>(0, 0); 
        int max_area = 0; 
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = zp; 
                    continue; 
                }
                
                
                if (dp[i - 1][j] == zp || dp[i][j - 1] == zp || dp[i - 1][j - 1] == zp) {
                    dp[i][j] = pair<int, int>(i, j); 
                    // cout << max_area << endl; 
                    if (max_area == 0) {
                        // cout << "hi" << endl; 
                        max_area = 1; 
                    }
                } else {
                    int min_dif = min(i - dp[i - 1][j].first, j - dp[i][j - 1].second); 
                    if ((min_dif + 1) * (min_dif + 1) > max_area) {
                        max_area = (min_dif + 1) * (min_dif + 1); 
                    }
                    dp[i][j] = pair<int, int>(i - min_dif, j - min_dif); 
                    
                }
            }
        }
        
        return max_area; 
        
    }
};