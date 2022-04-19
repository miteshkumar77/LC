// https://leetcode.com/problems/majority-element

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return self.kthSmallest(nums, 0, len(nums) - 1, len(nums)//2 + 1)

        
        
    def partition(self, arr, l, r): 
      
        x = arr[r] 
        i = l 
        for j in range(l, r): 

            if arr[j] <= x: 
                arr[i], arr[j] = arr[j], arr[i] 
                i += 1

        arr[i], arr[r] = arr[r], arr[i] 
        return i
        
    def kthSmallest(self, arr, l, r, k): 
  
        if (k > 0 and k <= r - l + 1): 


            index = self.partition(arr, l, r) 

            if (index - l == k - 1): 
                return arr[index] 

            if (index - l > k - 1): 
                return self.kthSmallest(arr, l, index - 1, k) 

            return self.kthSmallest(arr, index + 1, r,  
                                k - index + l - 1) 
        return INT_MAX 

        