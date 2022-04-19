// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> pre(n, false);
        vector<bool> post(n, false);
        vector<bool> terminal(n, true);
        vector<int> ans;
        
        function<bool(int)> dfs = [&](int node) -> bool {
            if (pre[node] && !post[node]) {
                return false;
            }
            
            if (pre[node] && post[node]) {
                return terminal[node];
            }
            pre[node] = true;
            bool isTerminal = true;
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor)) {
                    isTerminal = false;
                }
            }
            post[node] = true;
            if (isTerminal) {
                ans.push_back(node);
            }
            terminal[node] = isTerminal;
            return isTerminal;
        };
        
        for (int i = 0; i < n; ++i) {
            if (!pre[i]) {
                dfs(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};