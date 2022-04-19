// https://leetcode.com/problems/largest-component-size-by-common-factor

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        
        int maxelem = *max_element(A.begin(), A.end()); 
        unordered_map<int, int> parent; 
        unordered_map<int, int> setsize;
        for (int i : A) {
            parent[i] = -1; 
            ++setsize[i]; 
        }
        
        function<int(int)> find = [&](int node) -> int {
            if (parent[node] == -1) {
                return node; 
            } else {
                parent[node] = find(parent[node]); 
                return parent[node]; 
            }
        };
        
        function<bool(int,int)> onion = [&](int a, int b) -> int {
            int pa = find(a); 
            int pb = find(b); 
            if (pa != pb) {
                parent[pa] = pb; 
                setsize[pb] += setsize[pa];
                return true; 
            }
            return false; 
        }; 
        
        
        vector<bool> sv(maxelem, true); 
        int lim = sqrt(maxelem); 
        int ans = 0; 
        for (int i = 2; i <= lim + 1; ++i) {
            parent.insert(make_pair(i, -1)); 
            setsize.insert(make_pair(i, 0)); 
            
            for (int j = 2 * i; j <= maxelem; j += i) {
                if (parent.find(j) != parent.end()) {
                    onion(i, j); 
                    ans = max(ans, setsize[find(i)]); 
                }
            }
        }
        
        return ans; 
    }
};