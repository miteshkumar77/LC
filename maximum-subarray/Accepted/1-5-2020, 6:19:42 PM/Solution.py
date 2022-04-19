// https://leetcode.com/problems/maximum-subarray

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        max_overall = nums[0]
        max_sf = 0
        max_curr = 0


        for i in nums:

            max_curr += i

            if max_curr < 0:
                max_curr = 0
            if max_sf < max_curr:
                max_sf = max_curr
            if i > max_overall:
                max_overall = i

        if (max_sf == 0 and max_overall < 0):
            return max_overall
        else:
            return max_sf
    