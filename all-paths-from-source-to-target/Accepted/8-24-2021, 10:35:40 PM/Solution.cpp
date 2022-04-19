// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    void gen(vector<vector<int>>& v, vector<int>& path, int node, vector<vector<int>> const& graph) {
        path.push_back(node);
        if (node + 1 == graph.size()) {
            v.push_back(path);
            path.pop_back();
            return;
        }
        for (int n : graph[node]) {
            gen(v, path, n, graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        vector<int> path;
        gen(v, path, 0, graph);
        return v;
    }
};