// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); 
        vector<vector<int> > graph(numCourses, vector<int>());
        stack<int> toporder;
        vector<bool> visited(numCourses, false);

        for (vector<int> p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                dfs(i, toporder, graph, visited);
            }
        }
        vector<int> order;
        order.reserve(numCourses);
        while(!toporder.empty()) {
            int top = toporder.top(); toporder.pop(); 
            if (indegree[top] != 0) {
                return vector<int>(); 
            }
            for (int n : graph[top]) {
                --indegree[n];
            }
            
            order.push_back(top); 
            
        }
        return order; 
    }
    
    
    
    void dfs(int node, stack<int>& toporder, vector<vector<int> >& graph, vector<bool>& visited) {
        visited[node] = true; 
        for (int n : graph[node]) {
            if (!visited[n]) {
                
                dfs(n, toporder, graph, visited);
            }
        }
        toporder.push(node);
    }
};