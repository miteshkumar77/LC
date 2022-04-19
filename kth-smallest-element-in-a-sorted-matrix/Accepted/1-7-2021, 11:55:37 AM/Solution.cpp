// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << numLTE(matrix, matrix[i][j]) << ' ';
            }
            cout << endl;
        }
        int l = matrix[0][0];
        int r = matrix.back().back();
        int ans = r;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            
            if (numLTE(matrix, mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    int numLTE(vector<vector<int>>& matrix, int num) {
        int col = matrix[0].size() - 1;
        int ans = 0;
        for (int row = 0; row < matrix.size() && col >= 0; ++row) {
            while(col >= 0 && matrix[row][col] > num) {
                --col;
            }
            ans += col + 1;
        }
        return ans;
    }
    
    bool check(vector<vector<int>>& matrix, int k, int i) {
        
        int lt = numLTE(matrix, i); 
        return lt >= k;
    }
};