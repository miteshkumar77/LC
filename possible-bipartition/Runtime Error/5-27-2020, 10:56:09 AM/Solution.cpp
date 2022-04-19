// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<list<int> > graph(N + 1, list<int>()); 
        for (vector<int> edge : dislikes) {
            graph[edge[0]].push_back(edge[1]); 
            graph[edge[1]].push_back(edge[0]); 
        }
        
        vector<int> color(N + 1, -1); 
        
        queue<int> bfsq; 
        bfsq.push(dislikes[0][0]);
        color[bfsq.front()] = 0; 
        while(!bfsq.empty()) {
            int top = bfsq.front();
            int curr_color = color[top]; 
            int n_color = (curr_color == 0)?1:0; 
            bfsq.pop(); 
            for (int neighbor : graph[top]) {
                if (curr_color == color[neighbor]) {
                    return false; 
                } else if (color[neighbor] == -1) {
                    color[neighbor] = n_color; 
                    bfsq.push(neighbor); 
                }
            }
        }
        
        return true; 
        
    }
};