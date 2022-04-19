// https://leetcode.com/problems/special-binary-string

class Solution(object):
    def makeLargestSpecial(self, s):
        """
        :type S: str
        :rtype: str
        """
        if len(s) == 2:
            return s
        lvl = 0
        special_strings = []
        pre = 1
        for i in range(1, len(s) - 1):
            if s[i] == '1':
                lvl += 1
            else:
                lvl -= 1
            if lvl == 0:
                special_strings.append(self.makeLargestSpecial(s[pre:i + 1]))
                pre = i + 1
        # print(sorted(special_strings))
        return '1' + "".join(sorted(special_strings, reverse=True)) + '0'
    
    
        