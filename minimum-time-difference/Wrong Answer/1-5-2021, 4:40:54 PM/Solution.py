// https://leetcode.com/problems/minimum-time-difference

class Solution(object):
    def findMinDifference(self, timePoints):
        ts = [[int(i) for i in j.split(':')] for j in timePoints]
        ms = set([x[0] * 60 + x[1] for x in ts])
        MOD = 24 * 60
        prev = -1
        ans = MOD
        for x in range(0, 2 * MOD + 1):
            i = x % MOD
            if i in ms:
                if prev != -1:
                    ans = min(ans, (i - prev + MOD) % MOD)
                    
                prev = i
        return ans