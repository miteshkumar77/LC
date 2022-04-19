// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, list<string>> graph; 
        stack<string> path; 
        

        for (vector<string> tk : tickets) {
            graph[tk[0]].push_back(tk[1]); 
        }
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            (it -> second).sort();  
        }
        
        dfs(graph, path, "JFK"); 
        vector<string> ans; 
        while(!path.empty()) {
            ans.push_back(path.top()); path.pop(); 
        }
        return ans; 
    }
    
    void dfs(unordered_map<string, list<string>>& graph, 
             stack<string>& path, string node) {
        
        if (graph.find(node) == graph.end() || 
            graph[node].size() == 0) {
            path.push(node); 
            return; 
        }
        
        string neighbor; 
        while(graph[node].size() != 0) {
            neighbor = *graph[node].begin(); 
            graph[node].pop_front(); 
            dfs(graph, path, neighbor); 
        }
        
        
        path.push(node); 
    }
};