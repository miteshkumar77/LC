// https://leetcode.com/problems/minimum-time-difference

class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        
        ts = [[int(i) for i in j.split(':')] for j in timePoints]
        ms = sorted([x[0] * 60 + x[1] for x in ts])
                
        
        MOD = 24 * 60; 
        ans = 900000000000000
        for i in range(len(ms)):
            ans = min(ans, (ms[i] + MOD - ms[(i + len(ms) - 1) % len(ms)]) % MOD)
        
        return ans
            