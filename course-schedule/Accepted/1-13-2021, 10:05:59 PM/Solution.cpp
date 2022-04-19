// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    bool isCycle(const vector<vector<int>>& graph, vector<bool>& exploring, vector<bool>& explored, int node) {
        if (explored[node]) return false;
        if (exploring[node] && !explored[node]) return true;
        exploring[node] = true;
        for (int neighbor : graph[node]) {
            if (isCycle(graph, exploring, explored, neighbor)) {
                return true;
            }
        }
        explored[node] = true;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> exploring(numCourses, false);
        vector<bool> explored(numCourses, false);
        
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto v : prerequisites) {
            graph[v[0]].push_back(v[1]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (isCycle(graph, exploring, explored, i)) {
                return false;
            }
        }
        return true;
    }
};