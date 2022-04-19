// https://leetcode.com/problems/frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp; 
        dp[stones[0]].insert(0);
        
        
        for (int stone : stones) {
            if (dp.find(stone) != dp.end()) {
                for (int lastJump : dp[stone]) {
                    int nextStonePlus = lastJump + 1 + stone;
                    int nextStoneMinus = lastJump - 1 + stone;
                    int nextStoneNeutral = lastJump + stone;
                    dp[nextStonePlus].insert(lastJump + 1);
                    if (lastJump > 1) {
                        dp[nextStoneMinus].insert(lastJump - 1);
                    }
                    dp[nextStoneNeutral].insert(lastJump);
                }
            }
        }
        
//         for (int i : stones) {
//             cout << i << ": ";
//             if (dp.find(i) != dp.end()) {
//                 for (int st : dp[i]) cout << st << ' ';
//             }
//             cout << endl;

//         }
        
        return dp.find(stones.back()) != dp.end();
        
    }
};