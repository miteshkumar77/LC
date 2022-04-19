// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution(object):
    def checkPalindromeFormation(self, a, b, cont=True):
        """
        :type a: str
        :type b: str
        :rtype: bool
        """
        
        def ispal(s):
            i = 0
            j = len(s) - 1
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True
        
        
        al = 0
        bl = 0
        ar = len(a) - 1
        br = len(b) - 1
        
        while al < br:
            if al == br - 1:
                break
            if a[al] == b[br]:
                br -= 1
            al += 1
        
        print(al, br)
        
        cand1 = a[0:al] + b[bl:]
        print(cand1)
        if ispal(cand1):
            return True
        
        if cont:
            return self.checkPalindromeFormation(b, a, False)
        else:
            return False
        
        