// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """
        ans = 0
        dp = [set() for i in arr]
        for i in range(len(arr)):
            d = set(arr[i])
            if len(d) == len(arr[i]):
                for j in range(i):
                    if len(d & dp[j]) == 0:
                        u = d | dp[j]
                        if len(u) > len(dp[i]):
                            dp[i] = u
        
                ans = max(ans, len(dp[i]))
        return ans