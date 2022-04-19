// https://leetcode.com/problems/remove-duplicate-letters

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = sorted([i for i in set(s)])
        return ''.join(l)
    
        
        