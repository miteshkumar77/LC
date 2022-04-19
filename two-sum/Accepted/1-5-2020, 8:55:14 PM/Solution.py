// https://leetcode.com/problems/two-sum

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        pairs = [None]*len(nums)
        for i in range(len(nums)):
            pairs[i] = (nums[i], i)
        

        pairs.sort(key=lambda x: x[0])

        i = 0
        j = len(pairs) - 1
        
        # print(pairs)
        while (i != j and pairs[i][0] + pairs[j][0] != target):
            # print(i, j, pairs[i][0], pairs[j][0])
            if pairs[i][0] + pairs[j][0] < target:
                i = i + 1
            else:
                j = j - 1
        return [pairs[i][1], pairs[j][1]]
        