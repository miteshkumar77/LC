// https://leetcode.com/problems/degree-of-an-array

class Solution(object):
    def findShortestSubArray(self, nums):
        
        occurrences = {}
        modes = {}
        first_occurrence = {}
        max_occurrence = 0
        min_length = len(nums)
        
        for j in range(len(nums)):
            
            i = nums[j]
            if i in occurrences:
                occurrences[i] += 1
            else:
                occurrences[i] = 0
                first_occurrence[i] = j
            
            if occurrences[i] > max_occurrence:
                max_occurrence = occurrences[i]
                min_length = j - first_occurrence[i] + 1
            elif occurrences[i] == max_occurrence:
                if min_length > j - first_occurrence[i] + 1:
                    min_length = j - first_occurrence[i] + 1
            
            
        return min_length
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
# class Solution(object):
#     def findShortestSubArray(self, nums):
        
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
        
#         modes = []
#         max_occurrences  = 0
#         occurrences = {}
        
#         for i in nums:
#             if i in occurrences:
#                 occurrences[i] += 1
#             else:
#                 occurrences[i] = 0
            
#             if occurrences[i] > max_occurrences:
#                 max_occurrences = occurrences[i]
#                 modes = []
#                 modes.append(i)
#             elif occurrences[i] == max_occurrences:
#                 modes.append(i)
#         max_reduce = 0
#         for i in modes:
#             curr_sum = 0
#             for j in range(len(nums)):
#                 if nums[j] == i:
#                     curr_sum += j
#                     break
            
            
#             for j in range(1, len(nums) + 1):
#                 if nums[len(nums) - j] == i:
#                     curr_sum += j - 1
#                     break
#             if curr_sum > max_reduce:
#                 max_reduce = curr_sum
#         return len(nums) - max_reduce
        
            