// https://leetcode.com/problems/unique-paths

import math

class Solution(object):
    def uniquePaths(self, m, n):
        return self.nCr(m + n - 2, n - 1)
    
    def nCr(self, n,r):
        f = math.factorial
        return f(n) / f(r) / f(n-r)
        