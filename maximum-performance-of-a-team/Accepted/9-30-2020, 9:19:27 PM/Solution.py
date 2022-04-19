// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution(object):
    def maxPerformance(self, n, speed, efficiency, k):
        """
        :type n: int
        :type speed: List[int]
        :type efficiency: List[int]
        :type k: int
        :rtype: int
        """
        paired = [(efficiency[i], speed[i]) for i in range(n)]
        paired.sort(key=lambda x: x[0])
        
        heap = []
        s = 0
        dp = [0 for i in range(n + 1)]
        
        for i in range(n - 1, 0, -1):
            if k == 1:
                continue
            if len(heap) == k - 1:
                if paired[i][1] > heap[0]:
                    s += paired[i][1] - heap[0]
                    heapq.heappop(heap)
                    heapq.heappush(heap, paired[i][1])
            else:
                s += paired[i][1]
                heapq.heappush(heap, paired[i][1])
            dp[i] = s
        ans = 0
        for i in range(n):
            ans = max(ans, paired[i][0] * (dp[i + 1] + paired[i][1]))
        return ans % (1000000007)
        
        