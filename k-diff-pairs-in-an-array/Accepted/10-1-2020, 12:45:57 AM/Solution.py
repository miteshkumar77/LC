// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution(object):
    def findPairs(self, nums, k):
        ct = defaultdict(lambda:0)
        ans = 0
        for i in nums:
            if k == 0:
                if ct[i] == 1:
                    ans += 1
            else:
                if i not in ct and i - k in ct:
                    ans += 1
                if i not in ct and i + k in ct:
                    ans += 1
            ct[i] += 1
        return ans