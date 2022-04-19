// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        function<bool(int,int)> ispal = [&](int i, int j) -> bool {
            while(i < j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }    
            
            return true;
        };
        int n = s.length();
        vector<bool> visited(n + 1, false);
        
        s = '#' + s;
        queue<pair<int,int>> bfsq;
        bfsq.push(make_pair(0, 0));
        
        while(!bfsq.empty()) {
            auto p = bfsq.front(); bfsq.pop();
            int i = p.first;
            int cuts = p.second;
            
            if (visited[i]) continue;
            
            if (i == n) return cuts - 1;
            
            visited[i] = true;
            for (int j = n; j > i; --j) {
                if (ispal(i + 1, j)) {
                    bfsq.push(make_pair(j, cuts + 1));
                }
            }
        }
        
        return -1;

    }
};