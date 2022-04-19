// https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        a = [set(s) for s in text.split(' ')]
        l = set(brokenLetters)
        return sum(len(x.intersection(l)) == 0 for x in a)





