// https://leetcode.com/problems/majority-element

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = self.majorityElementHelper(nums)
        return a    
    
    def majorityElementHelper(self, nums):
        print(nums)
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return nums[0]
        l = self.majorityElementHelper(nums[:len(nums)//2])
        r = self.majorityElementHelper(nums[len(nums)//2:])
        if (l is None and r is None):
            return None
        if (l is not None and r is None):
            return l
        if (l is None and r is not None):
            return l
        if (l == r):
            return l
        return None