// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution(object):
    def numOfStrings(self, patterns, word):
        """
        :type patterns: List[str]
        :type word: str
        :rtype: int
        """
        ans = 0
        for p in patterns:
            if word.find(p) != -1:
                ans += 1
        return ans