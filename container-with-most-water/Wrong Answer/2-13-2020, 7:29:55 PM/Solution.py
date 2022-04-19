// https://leetcode.com/problems/container-with-most-water

class Solution(object):
    def vol(self, left_ptr, right_ptr, arr):
        return min(arr[left_ptr], arr[right_ptr]) * (right_ptr - left_ptr)
    
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_left_idx = 0
        max_right_idx = len(height) - 1
        
        for i in range(1, len(height) - 1):
            if (len(height) - 1 - i) * height[i] > (len(height) - 1 - max_left_idx) * height[max_left_idx] :
                max_left_idx = i
        
        for i in range(max_left_idx + 1, len(height)):
            if (self.vol(max_left_idx, i, height) > self.vol(max_left_idx, max_right_idx, height)):
                max_right_idx = i
        
        return self.vol(max_left_idx, max_right_idx, height)