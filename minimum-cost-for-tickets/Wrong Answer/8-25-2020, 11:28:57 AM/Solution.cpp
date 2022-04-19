// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<bool> included(365, false); 
        for (int day : days) included[day - 1] = true;
        
        vector<int> mincost(365); 

        if (included[0]) {
            mincost[0] = costs[0]; 
        } else {
            mincost[0] = 0; 
        }
        for (int i = 1; i < mincost.size(); ++i) {
            if (included[i]) {
                mincost[i] = mincost[i - 1] + costs[0]; 
                if (i - 7 >= 0)
                    mincost[i] = min(mincost[i], mincost[i - 7] + costs[1]); 
                if (i - 30 >= 0) 
                    mincost[i] = min(mincost[i], mincost[i - 30] + costs[2]); 
            } else {
                mincost[i] = mincost[i - 1]; 
            }
        }
        
        return mincost.back(); 
        
    }
};