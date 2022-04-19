// https://leetcode.com/problems/jump-game

class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        if len(nums) <= 1:
            return True
        
        max_n = nums[0]
        max_i = 0
        max_curr = 0
        max_curr_i = 0
        
        while(True):
            
            if max_n == 0:
                return False
            for i in range(max_i + 1, max_n + max_i + 1):
                if i >= len(nums) - 1:
                    return True
                
                if nums[i] > max_curr:
                    max_curr = nums[i]
                    max_curr_i = i
                    
                    
            max_n = max_curr
            max_i = max_curr_i
            max_curr = 0
            
                