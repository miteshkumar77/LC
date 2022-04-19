// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int check(vector<vector<int>> const& mat, int x, int k) {
        int n = mat.size();
        int m = mat[0].size(); 
        int i = n-1;
        int j = 0;
        int elems = 0;
        while(i >= 0 && j < m) {
            if (mat[i][j] > x) {
                --i;
            } else {
                elems += (i+1);
                ++j;
            }
        }
        return elems >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0]; int r = matrix.back().back();
        int ans = r;
        int mid;
        int res;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(matrix, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};