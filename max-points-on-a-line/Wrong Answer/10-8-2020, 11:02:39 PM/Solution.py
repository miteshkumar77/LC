// https://leetcode.com/problems/max-points-on-a-line

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:

        """
        :type points: List[List[int]]
        :rtype: int
        """
        
        
        if len(points) <= 1:
            return len(points)
        
        
        from fractions import Fraction
        import math
        
        ans = 0
        
        for i in range(len(points)):
            d = defaultdict(lambda: 0)    
            for j in range(i + 1, len(points)):
                
                num = points[j][1] - points[i][1]
                den = points[j][0] - points[i][0]
                
                F = math.nan if den == 0 else Fraction(num, den)
                
                d[F] += 1
                
                ans = max(ans, d[F] + 1)
        return ans