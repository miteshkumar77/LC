// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e = 0;
        int o = 0;
        
        for (int i : position) {
            if (i % 2 == 0) {
                ++e;
            } else {
                ++o;
            }
        }
        return min(e, o);
    }
};