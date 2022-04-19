// https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, vector<unordered_map<int,int>>& parents, int node, int parent, int depth) {
        parents[node][parent] = depth;
        for (int neighbor : graph[node]) {
            dfs(graph, parents, neighbor, parent, depth + 1);
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_map<int, int>> parents(n);
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto& e : prerequisites) {
            graph[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }
        
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                dfs(graph, parents, i, i, 0);
            }
        }
        
        vector<bool> ans;
        ans.reserve(queries.size()); 
        
        for (auto& e : queries) {
            bool ok = false;
            for (auto& p : parents[e[0]]) {
                if (parents[e[1]].count(p.first) && parents[e[1]][p.first] > p.second) {
                    ok = true;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
        
    }
};