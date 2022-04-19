// https://leetcode.com/problems/reverse-integer

import math

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        i = 0
        abs_x = abs(x)
        ret = 0
        
        while abs_x != 0:
            
            power_10 = 10 ** int(math.log10(abs_x))
            ret += (10 ** i) * (abs_x//power_10)
            abs_x = abs_x % power_10
            i += 1
        
        if x < 0:
            return (-1) * ret
        else:
            return ret
        
        