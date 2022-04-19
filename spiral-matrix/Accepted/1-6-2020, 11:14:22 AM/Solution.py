// https://leetcode.com/problems/spiral-matrix

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        
        i = 0
        j = -1
        
        if len(matrix) == 0:
            return []
        
        result = []*len(matrix) * len(matrix[0])
        
        r = len(matrix[0])
        d = len(matrix) - 1
        l = len(matrix[0]) - 1
        u = len(matrix) - 2
        
        while(True):
            
            j += 1
            if r <= 0:
                break
            for x in range(r):
                result.append(matrix[i][j])
                j += 1
            j -= 1
            r -= 2
            
            i += 1
            if d <= 0:
                break
            for x in range(d):
                result.append(matrix[i][j])
                i += 1
            i -= 1
            d -= 2
            
            j -= 1
            if l <= 0:
                break
            for x in range(l):
                result.append(matrix[i][j])
                j -= 1
            j += 1
            l -= 2
            
            i -= 1
            if u <= 0:
                break
            for x in range(u):
                result.append(matrix[i][j])
                i -= 1 
            i += 1
            u -= 2
            
        return result
            
            
        
                