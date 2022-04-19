// https://leetcode.com/problems/number-of-islands

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        if len(grid) == 0:
            return 0

        lands = []
        ans = 0
        R, C = len(grid), len(grid[0])

        for row in range(R):
            for col in range(C):
                grid[row][col] = int(grid[row][col])

        for row in range(R):
            for col in range(C):
                if grid[row][col] == 1:
                    lands.append([row, col])

        if len(lands) == 0:
            return 0

        from collections import deque
        directions = [[1, 0],
                      [0, 1],
                      [0, -1],
                      [-1, 0]]

        def is_valid(x, y):
            return (0 <= x < R) and (0 <= y < C) and grid[x][y]==1

        def bfs(x, y):

            q = deque()
            q.append([x, y])

            while q:
                x, y = q.popleft()

                for d in directions:
                    new_x, new_y = x + d[0], y + d[1]
                    if is_valid(new_x, new_y):
                        grid[new_x][new_y] = 0
                        q.append([new_x, new_y])


        visited = set()
        for x, y in lands:
            land_name = str(x) + "_" + str(y)

            if land_name not in visited and grid[x][y] == 1:
                visited.add(land_name)
                bfs(x, y)
                ans += 1

        return ans

# class Solution(object):
#     def numIslands(self, matrix):
#         result = 0
#         for i in range(len(matrix)):
#             for j in range(len(matrix[i])):
#                 if matrix[i][j] == "1":
#                     self.returnSize(matrix, i, j)
#                     result += 1

#         return result

	
#     def returnSize(self, matrix, i, j):
        
#         if 0 <= i < len(matrix) and 0 <= j < len(matrix[0]) and matrix[i][j] == "1":
            
#             matrix[i][j] = "0"
            
#             self.returnSize(matrix, i - 1, j)
#             self.returnSize(matrix, i + 1, j)
#             self.returnSize(matrix, i, j + 1)
#             self.returnSize(matrix, i, j - 1)

