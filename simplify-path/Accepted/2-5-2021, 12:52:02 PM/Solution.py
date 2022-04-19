// https://leetcode.com/problems/simplify-path

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        path = path.split('/')
        
        stk = []
        for item in path:
            if item == "." or item == "":
                continue
            if item == "..":
                if len(stk) != 0:
                    stk.pop()
            else:
                stk.append(item)
        return '/' + '/'.join(stk)
    
        