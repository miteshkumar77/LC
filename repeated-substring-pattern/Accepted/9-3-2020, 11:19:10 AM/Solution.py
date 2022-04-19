// https://leetcode.com/problems/repeated-substring-pattern

class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in range(1, len(s)//2 + 1):
            if s == s[:i] * (len(s)//i):
                return True 
        return False 
            
        