// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> sets(n, -1); 
        if (edges.size() != n - 1) {
            return false; 
        }
        function<int(int)> find = [&](int i) -> int {
            if (sets[i] == -1) {
                return i; 
            }
            sets[i] = find(sets[i]); 
            return sets[i]; 
        };
        
        
        function<bool(int, int)> onion = [&](int i, int j) -> int {
            int ip = find(i);
            int jp = find(j); 
            if (ip == jp) {
                return false; 
            }
            sets[ip] = jp; 
            return true; 
        }; 
        
        
        for (vector<int> e : edges) {
            if (!onion(e[0], e[1])) {
                return false; 
            }
        }
        
        int num_roots = 0; 
        for (int i = 0; i < sets.size(); ++i) {
            // cout << sets[i] << ' ' ;
            if (sets[i] == -1) {
                ++num_roots; 
            }
            if (num_roots == 2) {
                return false; 
            }
        }
        return true; 
    }
};