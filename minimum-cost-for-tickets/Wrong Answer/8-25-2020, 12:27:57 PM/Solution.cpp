// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<bool> included(365, false); 
        for (int day : days) included[day - 1] = true;
        
        vector<int> mincost(365); 

        // if (included[0]) {
        //     mincost[0] = min(costs[0], min(costs[1], costs[2])); 
        // } else {
        //     mincost[0] = 0; 
        // }
        mincost[0] = 0; 
        for (int i = 1; i < mincost.size(); ++i) {
            mincost[i] = mincost[i - 1]; 
            if (included[i]) {
                mincost[i] += costs[0]; 
                mincost[i] = min(mincost[max(0, i - 7)] + costs[1], mincost[i]); 
                mincost[i] = min(mincost[max(0, i - 30)] + costs[2], mincost[i]); 
            }
        }
        return mincost.back(); 
        
        
    }
};