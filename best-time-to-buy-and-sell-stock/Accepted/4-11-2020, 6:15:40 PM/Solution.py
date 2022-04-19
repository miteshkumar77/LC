// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if len(prices) == 0:
            return 0
        
        maxProfit = 0
        buy = prices[0]
        
        for i, j in enumerate(prices):
            if (j < buy):
                buy = j
            elif (j - buy > maxProfit):
                maxProfit = j - buy
        
        return maxProfit