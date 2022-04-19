// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution(object):
    def findPairs(self, nums, k):
        
        ans = set()
        seen = set()
        for i in nums:
            if i - k in seen:
                ans.add((i, i - k))
            if i + k in seen:
                ans.add((i + k, i))
            seen.add(i)
        return len(ans)