// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        ret = [0, 0]
        ret[0] = self.first(nums, target)
        ret[1] = self.second(nums, target)
        return ret
    
    def first(self, nums, target):
        l = 0
        r = len(nums) - 1
        
        while (l < r) :
            if (nums[(l + r)//2] >= target):
                r = (l + r)//2 - 1
            else :
                l = (l + r)//2 + 1
        
        
        if (nums[l] == target) :
            return l
        return -1
    
    def second(self, nums, target) :
        l = 0
        r = len(nums) - 1
        while (l < r) :
            if (nums[(l + r)//2] > target):
                r = (l + r)//2 - 1
            else :
                l = (l + r)//2 + 1
        
        l -= 1
        if (nums[l] == target) :
            return l
        return -1
 
        
    
        