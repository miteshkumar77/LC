// https://leetcode.com/problems/word-break

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        D = [False] * (len(s) + 1)
        D[0] = True
        for i in range(len(D)):
            
            if D[i]:
                S = ''
                for j in range(i + 1, len(D)):
                    S += s[j - 1]
                    print(S)
                    if S in wordDict:
                        D[j] = True
        
        return D[len(D) - 1] 
            