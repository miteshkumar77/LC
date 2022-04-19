// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
       
        int dp[word1.length() + 1][word2.length() + 1]; 
        dp[0][0] = 0; 
        for (int i = 0; i <= word1.length(); ++i) {
            for (int j = 0; j <= word2.length(); ++j) {
                if (i == 0) {
                    *(*(dp + i) + j) = j; 
                }
                
                if (j == 0) {
                    dp[i][j] = i; 
                }
            }
        }
        
        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                vector<int> sp = {
                    dp[i - 1][j - 1] + !(word1[i - 1] == word2[j - 1]),
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1
                }; 
                dp[i][j] = *min_element(sp.begin(), sp.end()); 
            }
        }
        
        return dp[word1.length()][word2.length()]; 
        
        
    }
};