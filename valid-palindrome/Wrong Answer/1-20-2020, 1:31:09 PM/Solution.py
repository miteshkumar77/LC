// https://leetcode.com/problems/valid-palindrome

class Solution(object):
    def isPalindrome(self, s):
        
        s = s.lower()
        for i in range(len(s)):
            j = len(s) - 1 - i
            
            if i <= j:
                break
            
            if s[i] != s[j]:
                return False
        
        return True
    
            
            
            
        
        