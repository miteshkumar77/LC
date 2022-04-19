// https://leetcode.com/problems/word-break

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        D = [-1] * (len(s) + 1)
        D[0] = 0
        for i in range(len(D)):
            
            if D[i] != -1:
                S = ''
                for j in range(i + 1, len(D)):
                    S += s[j - 1]
                    print(S)
                    if S in wordDict:
                        D[j] = i
       