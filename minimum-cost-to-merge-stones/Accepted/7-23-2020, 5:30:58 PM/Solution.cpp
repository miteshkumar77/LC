// https://leetcode.com/problems/minimum-cost-to-merge-stones

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        vector<vector<vector<int>> > dp(stones.size(), vector<vector<int>>(stones.size(), vector<int>(K + 1, -2)));
        vector<int> prefsum(stones.size() + 1, 0); 
        for (int i = 1; i <= stones.size(); ++i) {
            prefsum[i] = stones[i - 1] + prefsum[i - 1]; 
        }
        
        
        function<int(int, int)> getsum = [&] (int i, int j) -> int {
            return prefsum[j + 1] - prefsum[i]; 
        };
        
        function<int(int, int, int)> merge = [&] (int L, int R, int piles) -> int {
            
            if (dp[L][R][piles] != -2) {
                return dp[L][R][piles]; 
            }
            
            if (R - L + 1 < piles) {
                return -1; 
            }
            if ((R - L + 1 - piles) % (K - 1) != 0) {
                return -1; 
            }
            
            if (piles == 1) {
                if (L == R) return 0;
                else {
                    dp[L][R][piles] = getsum(L, R) + merge(L, R, K); 
                    return dp[L][R][piles]; 
                }
            }
            
            int ans = -1; 
            for (int i = L; i < R; ++i) {
                int lans = merge(L, i, 1); 
                int rans = merge(i + 1, R, piles - 1); 
                if (lans >= 0 && rans >= 0) {
                    if (ans == -1 || ans > (lans + rans)) {
                        ans = lans + rans;  
                    }
                }
            }
            dp[L][R][piles] = ans;
            return ans; 
        };
        
        return merge(0, stones.size() - 1, 1); 
    }
    
    
    
};