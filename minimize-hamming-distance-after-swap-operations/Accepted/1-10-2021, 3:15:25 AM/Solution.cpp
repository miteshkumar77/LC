// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n, -1);
        vector<unordered_set<int>> children(n, unordered_set<int>());
        
        function<int(int)> find = [&](int node) -> int {
            if (parent[node] == -1) return node;
            parent[node] = find(parent[node]);
            return parent[node];
        };
        function<bool(int,int)> onion = [&](int a, int b) -> bool {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return false;
            parent[pa] = pb;
            return true;
        };
        
        for (auto sw : allowedSwaps) {
            onion(sw[0], sw[1]);
        }
        
        for (int i = 0; i < n; ++i) {
            children[find(i)].insert(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                unordered_map<int,int> ct_source;
                unordered_map<int,int> ct_target;
                for (int index : children[i]) {
                    // cout << index << ' ';
                    ++ct_source[source[index]];
                    ++ct_target[target[index]];
                }
                // cout << endl;
                for (auto p : ct_source) {
                    if (ct_target.find(p.first) != ct_target.end()) {
                        ans += min(p.second, ct_target[p.first]);
                    }
                }
            }
        }
        
        return n - ans;
        
    }
};