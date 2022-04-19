// https://leetcode.com/problems/number-of-islands

class Solution(object):
    def numIslands(self, matrix):
        result = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == "1":
                    self.returnSize(matrix, i, j)
                    result += 1

        return result

	
    def returnSize(self, matrix, i, j):
        
        if 0 <= i < len(matrix) and 0 <= j < len(matrix[0]) and matrix[i][j] == "1":
            
            matrix[i][j] = "0"
            
            self.returnSize(matrix, i - 1, j)
            self.returnSize(matrix, i + 1, j)
            self.returnSize(matrix, i, j + 1)
            self.returnSize(matrix, i, j - 1)

