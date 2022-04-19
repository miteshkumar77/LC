// https://leetcode.com/problems/permutations-ii

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        def generate(i, arr):
            if i == len(arr):
                ans.append([e for e in arr])
            
            seen = set()
            for x in range(i, len(arr)):
                if arr[x] in seen:
                    continue
                seen.add(arr[x])
                arr[i], arr[x] = arr[x], arr[i]
                generate(i + 1, arr)
                arr[i], arr[x] = arr[x], arr[i]
        
        generate(0, nums)
        return ans
        