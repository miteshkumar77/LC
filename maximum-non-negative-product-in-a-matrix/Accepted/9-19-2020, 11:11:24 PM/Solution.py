// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix

class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        mod = 1000000007
        dpmax = [[-100000000 for i in range(n + 1)] for j in range(m + 1)]
        dpmin = [[1000000000 for i in range(n + 1)] for j in range(m + 1)]
        dpmax[0][0] = 1
        dpmax[0][1] = 1
        dpmax[1][0] = 1
        dpmin[0][0] = 1
        dpmin[0][1] = 1
        dpmin[1][0] = 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                mult = grid[i - 1][j - 1]
                dpmax[i][j] = (mult * max(dpmax[i - 1][j], dpmax[i][j - 1])) 
                dpmin[i][j] = (mult * min(dpmin[i - 1][j], dpmin[i][j - 1]))
                
                if (grid[i - 1][j - 1] < 0):
                    dpmax[i][j], dpmin[i][j] = dpmin[i][j], dpmax[i][j]
        # for j in dpmax:
        #     print(j)
        # print(" ")
        # for j in dpmin:
        #     print(j)
        if dpmax[-1][-1] < 0:
            return -1
        return dpmax[-1][-1] % mod
                