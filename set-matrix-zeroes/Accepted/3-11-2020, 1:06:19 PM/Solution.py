// https://leetcode.com/problems/set-matrix-zeroes

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        max_v = 0; 
        for i in range(len(matrix)):
            for j in range(len(matrix[i])): 
                if matrix[i][j] > max_v: 
                    max_v = matrix[i][j]
        
        max_v = max_v + 1
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    for i2 in range(len(matrix)):
                        if matrix[i2][j] != 0:
                            matrix[i2][j] = max_v
                    for j2 in range(len(matrix[i])):
                        if matrix[i][j2] != 0:
                            matrix[i][j2] = max_v
        
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == max_v:
                    matrix[i][j] = 0
        