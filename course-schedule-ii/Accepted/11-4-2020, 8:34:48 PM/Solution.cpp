// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, unordered_set<int>> graph;
        
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
        }
        
        unordered_set<int> pre;
        unordered_set<int> post;
        vector<int> ans;
        
        function<bool(int)> dfs = [&](int node) -> bool {
            bool vpre = pre.find(node) != pre.end();
            bool vpost = post.find(node) != post.end();
            
            if (vpre && vpost) {
                return true;
            } else if (vpre && !vpost) {
                return false;
            }
            
            pre.insert(node);
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor)) {
                    return false;
                }
            }
            post.insert(node);
            ans.push_back(node);
            return true;
        };
        
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) {
                return vector<int>();
            }
        }
        
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};