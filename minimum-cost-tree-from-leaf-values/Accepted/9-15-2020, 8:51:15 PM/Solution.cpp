// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    typedef array<int,2> pii; 
    int mctFromLeafValues(vector<int>& arr) {
        
        // p.first = max leaf value
        // p.second = total sum
        int n = arr.size(); 
        int ans = INT_MAX; 
        vector<vector<pii>> dp(n, vector<pii>(n));
        vector<vector<bool>> set(n, vector<bool>(n, false)); 
        
        
        function<pii(int,int)> bt = [&](int L, int R) -> pii {
            if (L == R) {
                return pii{arr[L], 0}; 
            }    
            
            if (set[L][R]) {
                return dp[L][R]; 
            }
            int nodeval = -1; 
            int retsum = INT_MAX; 
            for (int i = L; i < R; ++i) {
                pii l = bt(L, i); 
                pii r = bt(i + 1, R); 
                
                int thissum = l[0] * r[0] + l[1] + r[1]; 
                int thisnodeval = max(l[0], r[0]); 
                if (retsum > thissum || retsum == thissum && thisnodeval < nodeval) {
                    retsum = thissum; 
                    nodeval = thisnodeval; 
                }
            }
            set[L][R] = true; 
            dp[L][R] = pii{nodeval, retsum}; 
            return pii{nodeval, retsum}; 
        };
        
        
        return bt(0, n - 1)[1]; 
        
    }
    
    

};