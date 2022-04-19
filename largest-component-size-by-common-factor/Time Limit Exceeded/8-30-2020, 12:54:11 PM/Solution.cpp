// https://leetcode.com/problems/largest-component-size-by-common-factor

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        vector<vector<int>> graph(A.size(), vector<int>()); 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (__gcd(A[i], A[j]) != 1) {
                    graph[i].push_back(j); 
                    graph[j].push_back(i); 
                }
            }
        }
        
        vector<bool> visited(A.size(), false); 
        
        function<int(int)> dfs = [&](int node) -> int {
            if (visited[node]) {
                return 0; 
            }
            int ans = 1; 
            visited[node] = true; 
            for (int neighbor : graph[node]) {
                ans += dfs(neighbor); 
            }
            return ans; 
        };
        
        int ans = 0; 
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                ans = max(ans, dfs(i)); 
                 
            }
        }
        return ans; 
    }
};