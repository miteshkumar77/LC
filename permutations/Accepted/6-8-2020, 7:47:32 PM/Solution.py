// https://leetcode.com/problems/permutations

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ans = []
        self.helper(nums, 0, [], ans)
        return ans 
    
    def helper(self, n, i, s, ans):
        if len(s) == len(n):
            ans.append(s)
            return 

        for k in range(len(s), 0, -1):
            self.helper(n, i + 1, s[:k] + [n[i]] + s[k:], ans)
        self.helper(n, i + 1, [n[i]] + s, ans)