// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (i != 0) {
                    matrix[i][j] += matrix[i - 1][j]; 
                }
                
                if (j != 0) {
                    matrix[i][j] += matrix[i][j - 1]; 
                }
                
                if (j != 0 && i != 0) {
                    matrix[i][j] -= matrix[i - 1][j - 1]; 
                }
            }
        }
        m = &matrix; 
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1); 
    }
    
    ~NumMatrix() {
        m = nullptr; 
    }
    
private:
    int getSum(int row, int col) {
        if (row == -1 || col == -1) {
            return 0; 
        }
        return (*m)[row][col]; 
    }
    vector<vector<int>>* m; 
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */