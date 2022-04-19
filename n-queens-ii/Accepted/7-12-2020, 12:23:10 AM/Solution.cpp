// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    int totalNQueens(int n) {
        
        int ans = 0; 
        list<array<int, 2> > cands; 
        dfs(ans, cands, 0, n); 
        return ans; 
    }
    
    
    
    void dfs(int& ans, list<array<int, 2> >& cands, int starti, int n) {
        
        
        if (cands.size() == n) {

            ++ans; 
            return; 
        }
        
        
        for (int j = 0; j < n; ++j) {
            bool valid = true; 
            for (auto it : cands) {
                if (checkFits(it, array<int, 2>{starti, j})) {
                    valid = false; 
                    break; 
                }
            }
            if (valid) {
                cands.push_back(array<int, 2>{starti, j}); 
                dfs(ans, cands, starti + 1, n); 
                cands.pop_back(); 
            }
            
        }
        
    }
    
    
    bool checkFits(array<int, 2> q1, array<int, 2> q2) {
        if (q1[0] == q2[0] || q1[1] == q2[1]) {
            return true; 
        }
        
        int a1 = q1[0]; int b1 = q1[1]; int an = q2[0]; int bn = q2[1];  
        return (a1 - b1 == an - bn) || (a1 + b1 == an + bn); 
    }
};