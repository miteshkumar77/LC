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
        
        return min(ms[1] - ms[0], (ms[0] + MOD - ms[1]) % MOD)
        