// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution(object):
    def checkPalindromeFormation(self, a, b, cont=True):
        """
        :type a: str
        :type b: str
        :rtype: bool
        """
        
        al = 0
        br = len(b) - 1
        
        ab = True
        ba = True
        
        while al < br:
            flag = False
            
            if ab and a[al] == b[br]:
                flag = True
            else:
                ab = False
            
            if ba and b[al] == a[br]:
                flag = True
            else:
                ba = False
            
            if flag:
                al += 1
                br -= 1
        
            if not (ab or ba):
                break
        return ab or ba
    
        
        
        
        
        
        