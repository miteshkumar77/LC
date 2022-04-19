// https://leetcode.com/problems/binary-search

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if (len(nums) == 0):
            return -1
        
        f = 0
        l = len(nums) - 1
        
        while (f <= l): 
            if (target < nums[(f + l)//2]) :
                l = (f + l) // 2 - 1
            elif (target > nums[(f + l)//2]) :
                f = (f + l)//2 + 1
            else :
                return (f + l)//2
        return -1
    