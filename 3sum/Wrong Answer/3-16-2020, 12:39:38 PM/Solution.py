// https://leetcode.com/problems/3sum

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        num_set = {k: v for v, k in enumerate(nums)};
        print(num_set)
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)): 
                if (-nums[i] - nums[j] in num_set and num_set[-nums[i] - nums[j]] > j):
                    del num_set[-nums[i] - nums[j]]
                    ret.append([nums[i], nums[j], -nums[i] - nums[j]])
        
        return ret 