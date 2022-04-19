// https://leetcode.com/problems/minimum-knight-moves

from collections import deque
class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        
        dx = [1, 1, 2, 2, -1, -1, -2, -2]
        dy = [2, -2, 1, -2, 1, -2, 1, -1]
        visited = set() 
        
        q = deque([((0, 0), 0)])
        while len(q) != 0:
            pos, dist = q.popleft()
            if pos not in visited:
                visited.add(pos)
                if pos == (x, y):
                    return dist
                for i in range(len(dx)):
                    q.append(((pos[0] + dx[i], pos[1] + dy[i]), dist + 1))
        return 0
        