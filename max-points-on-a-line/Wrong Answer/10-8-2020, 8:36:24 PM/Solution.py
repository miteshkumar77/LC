// https://leetcode.com/problems/max-points-on-a-line

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:

        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points) == 0:
            return 0
        
        from fractions import Fraction
        import math
        
        m = 1
        
        for i in range(len(points)):
            d = defaultdict(lambda: 0)
            for j in range(i + 1, len(points)):
                
                num = points[j][1] - points[i][1]
                den = points[j][0] - points[i][0]
                val = 0
                if den == 0:
                    val = math.nan
                else:
                    val = Fraction(num, den)
                d[val] += 1
                m = max(m, d[val] + 1)
        return m