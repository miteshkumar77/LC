// https://leetcode.com/problems/combinations

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ans = []
        self.nCk(list(range(1, n + 1)), [], 0, k, ans)
        return ans
    
    def nCk(self, n, s, i, k, ans):
        if k == 0:
            ans.append(s)
            return 
        for x in range(i, len(n) - k + 1):
    
            self.nCk(n, s + [n[x]], x + 1, k - 1, ans)