// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges

class Solution {
public:
    int minDays(int n) {
        vector<int> mindays(n + 1, -1); 
        // mindays[n] = 0; 
        
        queue<pair<int, int>> q; 
        q.push(make_pair(n, 0)); 
        
        while(!q.empty()) {
            auto p = q.front(); 
            
            q.pop(); 
            if (mindays[p.first] == -1) {
                if (p.first == 0) {
                    return p.second; 
                }
                mindays[p.first] = p.second; 
                if (p.first % 3 == 0) {
                    q.push(make_pair(p.first/3, p.second + 1)); 
                }
                if (p.first % 2 == 0) {
                    q.push(make_pair(p.first/2, p.second + 1));
                }
                
                if (p.first >= 1) { 
                    q.push(make_pair(p.first - 1, p.second + 1));
                }
            }
        }
        
        return mindays[0]; 
    }
};