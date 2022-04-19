// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = [0,0]
        res[0] = self.firstOccurence(nums, target)
        res[1] = self.lastOccurence(nums, target)
        return res
    
        
    
    def lastOccurence(self, nums, target):
        if (len(nums) == 0):
            return -1
        
        f = 0
        l = len(nums) - 1
        
        while (f < l - 1): 
            if (target < nums[(f + l)//2]) :
                l = (f + l) // 2 - 1
            elif (target > nums[(f + l)//2]) :
                f = (f + l)//2 + 1
            else :
                f = (f + l)//2
        
        if (nums[f] == target):
            return f
        return -1
    
    
    def firstOccurence(self, nums, target):
        if (len(nums) == 0):
            return -1

        f = 0
        l = len(nums) - 1

        while (f < l - 1): 
            if (target < nums[(f + l)//2]) :
                l = (f + l) // 2 - 1
            elif (target > nums[(f + l)//2]) :
                f = (f + l)//2 + 1
            else :
                l = (f + l)//2

        if (nums[f] == target):
            return f
        return -1
