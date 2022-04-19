// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if len(prices) == 0:
            return 0
        
        mn = prices[0]
        mp = 0
        
        for i in prices:
            if i < mn:
                mn = i
            elif i - mn > mp:
                mp = i - mn
        
        return mp