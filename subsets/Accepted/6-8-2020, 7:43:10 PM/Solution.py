// https://leetcode.com/problems/subsets

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ans = [] 
        for i in range(len(nums) + 1):
            self.nCk(nums, [], 0, i, ans)
        return ans  
    
    def nCk(self, n, s, i, k, ans):
        if k == 0:
            ans.append(s)
            return 
        for x in range(i, len(n) - k + 1):
            self.nCk(n, s + [n[x]], x + 1, k - 1, ans)