// https://leetcode.com/problems/richest-customer-wealth

class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max(map(sum, accounts))
        