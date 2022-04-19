// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>()); 
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]); 
        }
        vector<bool> pre(numCourses, false); vector<bool> post(numCourses, false); 
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(graph, i, pre, post)) {
                return false; 
            }
        }
        return true; 
        
        
    }
    
    
    bool dfs(vector<vector<int> >& graph, int node, vector<bool>& pre, vector<bool>& post) {
        if (pre[node] && post[node]) {
            return false; 
        }
        
        if (pre[node] && !post[node]) {
            return true; 
        }
        pre[node] = true; 
        for (int neighbor : graph[node]) {
            if (dfs(graph, neighbor, pre, post)) {
                return true; 
            }
        }
        post[node] = true; 
        return false; 
    }
};