// https://leetcode.com/problems/majority-element

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m_count = 1
        m_el = nums[0]
        
        for i in nums:
            if m_el == i:
                m_count += 1
            else:
                if m_count > 1:
                    m_count -= 1
                else:
                    m_el = i
        
        return m_el
        
        
        
        