// https://leetcode.com/problems/repeated-substring-pattern

class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return s in s[:len(s) - 1] + s[1:] 
        