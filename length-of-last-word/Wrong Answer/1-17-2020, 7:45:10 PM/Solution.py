// https://leetcode.com/problems/length-of-last-word

class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        # print(len(s))
        for i in range(len(s) - 1, 0, -1):
            # print(s[i])
            if s[i] == ' ':
                return i - 1
        return i
        