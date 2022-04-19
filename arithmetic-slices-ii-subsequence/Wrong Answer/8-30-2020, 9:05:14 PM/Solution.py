// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans = 0
        dp = defaultdict(lambda: 0)
        for i in range(1, len(A)):
            for j in range(i):
                delta = A[i] - A[j]
                ans += dp[(A[j], delta)]
                dp[(A[i], delta)] += dp[(A[j], delta)] + 1
            
        return ans 