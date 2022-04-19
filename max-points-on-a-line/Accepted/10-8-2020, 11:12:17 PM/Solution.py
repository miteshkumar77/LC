// https://leetcode.com/problems/max-points-on-a-line

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:

        """
        :type points: List[List[int]]
        :rtype: int
        """
        
        from fractions import Fraction
        import math
        
        ans = 0
        
        for i in range(len(points)):
            d = defaultdict(lambda: 0)
            num_eq = 0
            for j in range(i, len(points)):
                
                num = points[j][1] - points[i][1]
                den = points[j][0] - points[i][0]
                
                F = math.nan if den == 0 else Fraction(num, den)
                
                if num == 0 and den == 0:
                    num_eq += 1
                else:    
                    d[F] += 1
            
            ans = max(ans, num_eq)
            
            for v in d.values():
                ans = max(ans, v + num_eq)
            
        return ans