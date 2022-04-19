// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<string> > ans; 
        list<array<int, 2> > cands; 
        dfs(ans, cands, 0, 0, n); 
        return ans; 
    }
    
    
    
    void dfs(vector<vector<string>>& ans, list<array<int, 2> >& cands, int starti, int startj, int n) {
        if (starti >= n || startj >= n) {
            return; 
        }
        
        if (cands.size() == n) {

            vector<string> soln; 
            for (int i = 0; i < n; ++i) {
                soln.push_back(string(n, '.'));
            }
            for (auto it : cands) {
                soln[it[0]][it[1]] = 'Q'; 
            }
            ans.push_back(soln); 
            return; 
        }
        
        for (int i = starti; i < n; ++i) {
            for (int j = startj; j < n; ++j) {
                
                
                // if (n * n - i * n + j + 1 < n - cands.size()) {
                //     return; 
                // }
                startj = 0; 
                bool valid = true; 
                for (auto it : cands) {
                    if (checkFits(it, array<int, 2>{i, j})) {
                        valid = false; 
                        break; 
                    }
                }
                if (valid) {
                    cands.push_back(array<int, 2>{i, j}); 
                    dfs(ans, cands, i, j, n); 
                    cands.pop_back(); 
                }
            }
            starti = 0; 
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