// https://leetcode.com/problems/frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
         
        unordered_map<int, unordered_set<int>> jumps; 
        for (auto stone : stones) {
            jumps[stone] = unordered_set<int>(); 
        }
        
        jumps[0].insert(1); 
        
        for (int i = 0; i < stones.size() - 1; ++i) {
            int cstone = stones[i]; 

            for (auto jumpVal : jumps[cstone]) {
                auto it = jumps.find(cstone + jumpVal); 
                if (it != jumps.end()) {
                    (it -> second).insert(jumpVal + 1); 
                    (it -> second).insert(jumpVal); 
                    if (jumpVal != 1) {
                        (it -> second).insert(jumpVal - 1); 
                    }
                    
                }
            }
        }
        
        // for (int st : stones) {
        //     cout << st << ": ";
        //     for (auto j : jumps[st]) {
        //         cout << j << ' ';
        //     }
        //     cout << endl; 
        // }
        return jumps[stones.back()].size() != 0; 
    }
};