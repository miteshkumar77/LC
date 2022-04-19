// https://leetcode.com/problems/valid-parentheses

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """ 
        stack = []
        formula = {'(', '{', '['}
        formula_reverse = {')':'(',
                           ']': '[',
                           '}': '{'}
        for i in s:
            if i in formula:
                stack.append(i)
            else:
                if len(stack) == 0 or stack[-1] != formula_reverse[i]:
                    return False
                else:
                    stack.pop()
        return len(stack) == 0
    
                
                    
                
            
                
        