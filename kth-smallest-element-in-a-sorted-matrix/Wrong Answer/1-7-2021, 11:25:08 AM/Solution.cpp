// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        int ans = 0;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(matrix, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return matrix[ans / matrix.size()][ans % matrix[0].size()];
    }
    
    int numLTE(vector<vector<int>>& matrix, int num, int row) {
        int ans = 0;
        for (; row >= 0; --row) {
            auto it = lower_bound(matrix[row].begin(), matrix[row].end(), num);
            if (it == matrix[row].end()) {
                ans += matrix[row].size();
            } else {
                ans += it - matrix[row].begin() + 1;
            }
        }
        return ans;
    }
    
    bool check(vector<vector<int>>& matrix, int k, int i) {
        int row = i / matrix.size();
        int col = i % matrix[0].size();
        
        int lt = numLTE(matrix, matrix[row][col], row); 
        
        return lt <= k;
        
    }
};