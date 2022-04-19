// https://leetcode.com/problems/unique-paths

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m <= 0 or n <= 0:
            return ""
        dp = [1] * m
        for i in range(1, n):
            for j in range(1, m):
                dp[j] += dp[j-1]
        
        return dp[m-1]