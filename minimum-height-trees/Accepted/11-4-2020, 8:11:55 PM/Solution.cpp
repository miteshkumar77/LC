// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        unordered_set<int> cur;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() <= 1) {
                cur.insert(i);
            }
        }
        
        while(graph.size() > 2) {
            unordered_set<int> next;
            unordered_set<int> tmp;
            // for (int i : cur) cout << i << ' ';
            // cout << endl;
            for (int i : cur) {
                for (int n : graph[i]) {
                    tmp.insert(n);
                }
            }
            
            for (int i : cur) {
                graph[*graph[i].begin()].erase(i);
                graph.erase(i);
            }
            
            for (int i : tmp) {
                if (graph[i].size() <= 1) {
                    next.insert(i);
                }
            }
            
            next.swap(cur);
            
            // for (int i : cur) cout << i << ' ';
            // cout << endl;
        }
        
        return vector<int>(cur.begin(), cur.end());
        
    }
};