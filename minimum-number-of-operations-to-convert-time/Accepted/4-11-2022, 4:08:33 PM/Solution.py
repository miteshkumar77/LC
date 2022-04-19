// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time

class Solution(object):
    def convertTime(self, current, correct):
        """
        :type current: str
        :type correct: str
        :rtype: int
        """
        current = map(int, current.split(':'))
        correct = map(int, correct.split(':'))
        current = current[0] * 60 + current[1]
        correct = correct[0] * 60 + correct[1]
        T = 1450
        amt = (correct - current + T) % T
        print(amt)
        den = [60, 15, 5, 1]
        ans = 0
        for i in den:
            ans += amt//i
            amt %= i
        return ans