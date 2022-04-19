// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        function<bool(int,int)> ispal = [&](int i, int j) -> bool {
            if (dp[i][j] != 0) {
                cout << "ye" << endl;
                return dp[i][j] == 1;
            }
            if (i >= j) return true;
            bool ans = s[i] == s[j] && ispal(i + 1, j - 1);
            if (ans) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = -1;
            }
            return ans;
        };
        
        
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