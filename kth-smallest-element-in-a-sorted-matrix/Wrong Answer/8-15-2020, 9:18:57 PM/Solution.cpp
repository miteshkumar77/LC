// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    
        
        function<int(int)> lessthan = [&](int val) -> int {
            int i = matrix.size() - 1; 
            int j = 0; 
            int ans = 0; 
            while(i >= 0 && j < matrix[i].size()) {
                if (matrix[i][j] <= val) {
                    ans += i + 1; 
                    ++j; 
                } else {
                    --i; 
                }
            }
            
            return ans; 
        };
        
        
        int L = 0;
        int R = matrix.size() * matrix[0].size() - 1;  
        
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            int lt = lessthan(matrix[mid/matrix.size()][mid % matrix[0].size()]); 
            
            if (lt > k) {
                R = mid - 1; 
            } else if (lt < k) {
                L = mid + 1; 
            } else {
                return matrix[mid/matrix.size()][mid % matrix[0].size()];
            }
        }
        
        return -1; 
    }
};