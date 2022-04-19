// https://leetcode.com/problems/longest-common-prefix

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = ""
        if (len(strs) == 0):
            return ""
        
        if (len(strs) == 1):
            return strs[0]
        
        i = 0
        while (True):
            for j in range(1, len(strs)):
                if (i >= len(strs[j]) or strs[j][i] != strs[j - 1][i]):
                    return res
            res += strs[j][i]
            i += 1
        return res
                
            
        