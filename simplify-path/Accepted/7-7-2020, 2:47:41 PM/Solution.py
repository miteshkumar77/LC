// https://leetcode.com/problems/simplify-path

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        t_p = path.split('/')
        c_p = []
        for s in t_p:
            if (s != '' and s != "."):
                if (s == ".."):
                    if len(c_p) != 0:
                        c_p.pop() 
                else:
                    c_p.append(s)
        ans = '' 
        for s in c_p:
            ans += s
            ans += '/'
        ans = '/' + ans[:len(ans) - 1] 
        return ans 