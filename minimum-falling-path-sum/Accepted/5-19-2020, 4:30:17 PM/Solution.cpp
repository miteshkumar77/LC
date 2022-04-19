// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> kevwangster(A.size(), vector<int>(A.size(), 0)); 
        
        for (int i = 0; i < A.size(); ++i) {
            kevwangster[0][i] = A[0][i]; 
        }
        
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                list<int> options; 
                if (j > 0) {
                    options.push_back(kevwangster[i - 1][j - 1]); 
                }
                
                options.push_back(kevwangster[i - 1][j]); 
                
                if (j < A.size() - 1) {
                    options.push_back(kevwangster[i - 1][j + 1]); 
                }
                
                kevwangster[i][j] = (*min_element(options.begin(), options.end())) + A[i][j]; 
            }
        }
        
        return *min_element(kevwangster.back().begin(), kevwangster.back().end()); 
    }
};