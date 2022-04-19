// https://leetcode.com/problems/container-with-most-water

class Solution(object):
    def vol(self, left_ptr, right_ptr, arr):
        return min(arr[left_ptr], arr[right_ptr]) * (right_ptr - left_ptr)
    
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_i = 0
        max_j = len(height) - 1
        
        i = 0
        j = max_j
        
        while(i < j):
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
            if self.vol(i, j, height) > self.vol(max_i, max_j, height):
                max_i = i
                max_j = j
        return self.vol(max_i, max_j, height)