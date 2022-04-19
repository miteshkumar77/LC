// https://leetcode.com/problems/pizza-with-3n-slices

class Solution(object):
    
    
    
    def maxSizeSlices(self, slices):
        """
        :type slices: List[int]
        :rtype: int
        """
        dp = dict()
        
        def sol(slic):
            
            if len(slic) == 0:
                return 0
            tup = tuple(slic)
            if tup in dp:
                return dp[tup]
            ans = -1
            for i in range(len(slic)):
                if i == 0:
                    ans = max(ans, slic[i] + sol(slic[2:len(slic) - 1]))
                elif i == len(slic) - 1:
                    ans = max(ans, slic[i] + sol(slic[1:len(slic) - 2]))
                else:
                    ans = max(ans, slic[i] + sol(slic[0:i - 1] + slic[i + 2:]))
            dp[tup] = ans
            return ans
        
        return sol(slices)