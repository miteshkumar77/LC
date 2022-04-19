// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1); 
        vector<int> tmp(rowIndex + 1); 

        ans[0] = 1; 
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    tmp[j] = 1; 
                } else {
                    tmp[j] = ans[j - 1] + ans[j]; 
                }
            } 
            tmp.swap(ans); 
        }
        
        return ans; 
    }
};