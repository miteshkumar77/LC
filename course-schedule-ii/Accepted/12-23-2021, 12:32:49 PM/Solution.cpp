// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    bool dfs(int node, vector<bool>& pre, vector<bool>& post, vector<int>& ord, vector<vector<int>>& graph) {
        if (post[node]) {
            return true;
        }
        if (pre[node]) {
            return false;
        }
        pre[node] = true;
        for (int prereq : graph[node]) {
            if (!dfs(prereq, pre, post, ord, graph)) return false;
        }
        ord.push_back(node);
        post[node] = true;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> pre(numCourses, false);
        vector<bool> post(numCourses, false);
        vector<int> ord; ord.reserve(numCourses);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto const& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, pre, post, ord, graph)) {
                return {};
            }
        }
        // reverse(ord.begin(), ord.end());
        return ord;
    }
};