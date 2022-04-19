// https://leetcode.com/problems/longest-palindromic-substring

class Solution(object):
    def longestPalindrome(self, s):
        
        if len(s) < 2:
            return s
        
        max_pal = (0, 0)
        for i in range(2*len(s) - 3):
            f, l = self.expandAroundCenter(s, i)
            if max_pal[1] - max_pal[0] < l - f:
                max_pal = (f, l)
        
        return s[max_pal[0] + 1: max_pal[1]]
               
    def expandAroundCenter(self, s, c):
        i = None
        j = None
        if c%2 == 0:
            i = c//2
            j = c//2 + 1
        else:
            i = c//2
            j = c//2 + 2
        
        while(1): 
            if j == len(s) or i < 0 or s[i] != s[j]:
                # print(c, i, j, str(s[i + 1: j]), j - i)
                return (i, j)
            i -= 1
            j += 1
            
            
            
            
                
        
        