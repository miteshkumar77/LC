// https://leetcode.com/problems/special-binary-string

class Solution(object):
    def makeLargestSpecial(self, s):
        
        
        lvl = 0
        prev = 0
        special_substrings = []
        for i in range(len(s)):
            if s[i] == '1':
                lvl += 1
            else:
                lvl -= 1
            if lvl == 0:
                special_substrings.append('1' + self.makeLargestSpecial(s[prev + 1:i]) + '0')
                prev = i + 1
        return "".join(sorted(special_substrings, reverse=True))
    
        