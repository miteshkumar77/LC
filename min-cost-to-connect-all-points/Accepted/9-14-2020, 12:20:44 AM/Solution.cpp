// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        function<int(vector<int>&,vector<int>&)> dist = [&](vector<int>& p1, vector<int>& p2) -> int {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);     
        };
        
        vector<int> parent(n, -1); 
        function<int(int)> find = [&](int node) -> int {
            // cout << "find" << endl; 
            if (parent[node] == -1) {
                return node; 
            }
            parent[node] = find(parent[node]); 
            return parent[node]; 
        };
        
        
        function<bool(int,int)> onion = [&](int a, int b) -> int {
            int pa = find(a); 
            int pb = find(b); 
            if (pa == pb) {
                return false; 
            }
            parent[pa] = pb; 
            return true; 
        };
        
        function<bool(array<int,2>&,array<int,2>&)> cmp = [&](array<int,2>& a, array<int,2>& b) -> bool {
            return dist(points[a[0]], points[a[1]]) > dist(points[b[0]], points[b[1]]);     
        };
        
        priority_queue<array<int,2>, vector<array<int, 2>>, decltype(cmp)> pq(cmp); 
        
        // cout << "d" << endl; 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                pq.push(array<int,2>{i,j}); 
            }
        }
        
        // cout << "dd" << endl; 
        int ans = 0; 
        int k = n - 1; 
        while(k > 0) {
            array<int,2> top = pq.top(); pq.pop(); 
            if (onion(top[0], top[1])) {
                ans += dist(points[top[0]], points[top[1]]); 
                --k; 
            }
        }
        
        return ans; 
    }
    
    
    
};