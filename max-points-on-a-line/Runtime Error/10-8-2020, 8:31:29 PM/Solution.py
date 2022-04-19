// https://leetcode.com/problems/max-points-on-a-line

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        from fractions import Fraction
        
        m = 0
        
        for i in range(len(points)):
            d = defaultdict(lambda: 0)
            for j in range(i + 1, len(points)):
                
                num = points[j][1] - points[i][1]
                den = points[j][0] - points[i][0]
                d[Fraction(num, den)] += 1
                m = max(m, d[Fraction(num, den)] + 1)
        return m