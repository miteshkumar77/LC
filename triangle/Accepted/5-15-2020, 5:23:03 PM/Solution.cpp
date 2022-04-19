// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp1(triangle.size(), 0);
        vector<int> dp2(triangle.size(), 0); 
        dp1[0] = triangle[0][0]; 
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                int first = INT_MAX; 
                int second = INT_MAX; 
                
                if (j != 0) {
                    first = dp1[j - 1]; 
                }
                if (j != i) {
                    second = dp1[j]; 
                }
                
                dp2[j] = min(first, second) + triangle[i][j]; 
            }
            dp1.swap(dp2);  
        }
        
        return *min_element(dp1.begin(), dp1.end()); 
        
    }
};