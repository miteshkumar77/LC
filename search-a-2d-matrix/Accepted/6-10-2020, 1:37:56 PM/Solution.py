// https://leetcode.com/problems/search-a-2d-matrix

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        A=matrix
        B=target
        if not A:
            return 0
        m=len(A)
        n=len(A[0])
        q=[]
        for i in range(m):
            for j in reversed(range(n)):
                q.append((i,j))
                break
            break
        while q:
            i,j=q.pop()
            if B < A[i][j] and j > 0:
                q.append((i,j-1))
            if B > A[i][j] and i < m-1:
                q.append((i+1,j))
            if A[i][j] == B:
                return True
        return False