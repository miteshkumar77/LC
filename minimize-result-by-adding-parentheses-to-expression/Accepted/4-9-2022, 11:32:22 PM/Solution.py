// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression

class Solution(object):
    def evhelp(self, expression):
        he = ""
        for c in expression:
            if c == '(':
                if len(he) > 0 and he[len(he)-1:].isdigit():
                    he += '*'
            if c.isdigit():
                if len(he) > 0 and he[-1] == ')':
                    he += '*'
            he += c
        return eval(he)
    
    def minimizeResult(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        """

        1+1
        012
        """
        best = 9999999999999
        bestexp = expression
        for i in range(0, expression.find('+')):
            for j in range(expression.find('+')+1, len(expression)):
                if expression[i] != '+' and expression[j] != '+':
                    newexp = expression[0:i] + '(' + expression[i : j+1] + ')' + expression[j+1:]
                    newev = self.evhelp(newexp)
                    if newev < best:
                        best = newev
                        bestexp = newexp
        
        return bestexp