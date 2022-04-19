// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        for (int x = 0; x < matrix.size() + matrix[0].size() - 1; ++x) {
            int i; 
            int j; 
            if (x < matrix.size()) {
                i = x; 
                j = 0; 
            } else {
                i = 0; 
                j = x - matrix.size() + 1; 
            }
            priority_queue<int, vector<int>, greater<int>> pq; 
            int is = i; 
            int js = j; 
            while(i < matrix.size() && j < matrix[0].size()) {
                pq.push(matrix[i++][j++]);
            }
            i = is; j = js; 
            while(i < matrix.size() && j < matrix[0].size()) {
                matrix[i++][j++] = pq.top(); pq.pop(); 
            }
        }
        return matrix; 
    }
};